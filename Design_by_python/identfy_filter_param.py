import numpy as np
from control.matlab import *
import scipy.optimize as optimize
from scipy import signal
from scipy import interpolate
import matplotlib.pyplot as plt
from scipy.optimize import LinearConstraint, BFGS

import os
import csv

PI = np.pi

FS = 44100
AMPLITUDE_EXP = 4.0
OVERSAMPLING_RATIO = 8
TAP = 72
FREQ_ANALYSIS_POINTS = 2048
MAX_ITER = 20
RMSE_WEIGHTING = 0.5 # 0~1.0  0に近いと時間軸優先、1.0に近いと周波数軸優先
TS_OVERSAMPLING = 1 / (FS * OVERSAMPLING_RATIO)
TAP_OVERSAMPLING = TAP * OVERSAMPLING_RATIO


class FIR_filter:
    def __init__(self, h_array_):
        self.h_array = np.copy(h_array_)
    
    def execute_FIR_filter(self, x):
        # scypi.signalによるコード(処理が速い)
        y = signal.lfilter(self.h_array, 1, x)
        
        # ベタ書きによるコード(処理が遅い)
        #size_data = x.size
        #size_tap = self.h_array.size
        #y = np.zeros(size_data)
        #for index_data in range(size_data):
            #y[index_data] = 0           
            #for tap in range(size_tap):
                #if index_data - tap >= 0:
                    #y[index_data] += self.h_array[tap] * x[index_data - tap]
        return y

class IIR_Filter:
    def __init__(self):
        self.fs = FS * OVERSAMPLING_RATIO  # サンプリング周波数
        self.wp = FS * OVERSAMPLING_RATIO * 0.42  # 通過域遮断周波数[Hz]
        self.ws = FS * OVERSAMPLING_RATIO * 0.499  # 阻止域遮断周波数[Hz]
        self.gpass = 0.05  # 通過域最大損失量[dB]
        self.gstop = 150  # 阻止域最小減衰量[dB]
        self.analog = False  # ディジタルフィルタなのでFalse
        self.ftype = 'butter'  # バタワース
        self.output = 'ba'  # baまたはtf型
        
        self.b, self.a = signal.iirdesign(self.wp, self.ws, self.gpass, self.gstop,
                                self.analog, self.ftype, self.output, self.fs)
    
    def execute_IIR_filter(self, x):
        y = signal.lfilter(self.b, self.a, x)
        return y

def base_func(param, input):
    # フィルタを定義
    fir = FIR_filter(param)
    y = fir.execute_FIR_filter(input[1])
    return y

def freq_resp(param):
    # 周波数応答を算出
    w, h = signal.freqz(param, 1.0, FREQ_ANALYSIS_POINTS) # 1024はグラフの要素数
    amp_dB = 20 * np.log10(np.abs(h))
    angles = np.unwrap(np.angle(h))
    freq = w * FS * OVERSAMPLING_RATIO
    return [freq, amp_dB, angles]

def rmse_res(param, exp, input, in_freq_resp):
    result1 = base_func(param, input)
    _, result2, _ = freq_resp(param)
    
    residual1 = exp[1] - result1
    residual2 = in_freq_resp[1] - result2
    resid_ = np.sqrt((residual1 * residual1).sum() / len(exp[0])) * (1.0 - RMSE_WEIGHTING)
    + np.sqrt((residual2 * residual2).sum() / len(in_freq_resp[1])) * RMSE_WEIGHTING
    return resid_

def plot_fig(input, exp, param, in_freq_resp):
    result = base_func(param, input)
    
    plt.figure()
    plt.plot(exp[0], exp[1], label = "experiment")
    plt.plot(input[0], result, label="result")
    #plt.plot(input[0], input[1], label="input")
    
    # 周波数応答を算出
    freq, amp_dB, angles = freq_resp(param)
    
    plt.figure()
    plt.semilogx(freq, amp_dB, 'b')
    plt.semilogx(in_freq_resp[0], in_freq_resp[1], 'r')
    #plt.semilogx(omega, angles, 'g')
    
    plt.show()

# 実験データ用ノイズフィルタ定義
exp_filter = IIR_Filter()

# 実験データCSVを読み込み
with open('impulseResponse_44.1kHz.csv') as f_exp:
    reader = csv.reader(f_exp)
    expdata_read = np.array([row for row in reader]).T
    expdata0 = expdata_read.astype('double')

# 実験データをリサンプリング
f1_x = np.arange(0, 0.0024, TS_OVERSAMPLING).T
f1 = interpolate.interp1d(expdata0[0], expdata0[1])
f1_y = f1(f1_x)
f1_y_normalized = f1_y / AMPLITUDE_EXP
f1_y_filtered = exp_filter.execute_IIR_filter(f1_y_normalized)
expdata = np.array([f1_x, f1_y_filtered])

# 入力データCSVを読み込み
with open('impulseInput_44.1kHz.csv') as f_input:
    reader = csv.reader(f_input)
    indata_read = np.array([row for row in reader]).T
    indata0 = indata_read.astype('double')

# 入力データをリサンプリング
f2_x = np.arange(0, 0.0024, TS_OVERSAMPLING).T
f2 = interpolate.interp1d(indata0[0], indata0[1])
f2_y = f2(f2_x)
f2_y_normalized = f2_y / f2_y.max()
indata = np.array([f2_x, f2_y_normalized])

# フィルタ周波数特性を定義
freq = np.array([0.0, 17500, 20000, 22500, 25000, 26000, 40000, 352800])
gain = np.array([0.0, 0.0, -0.06, -50, -100, -155, -165, -170])
f3_x, _, _ = freq_resp([0,0,0,0])
f3 = interpolate.interp1d(freq, gain, fill_value='extrapolate')
f3_y = f3(f3_x)
FrequencyResponse = np.array([f3_x, f3_y]) 

# FIRフィルタの初期パラメータを定義
#params = np.zeros(TAP)
params = signal.firwin(numtaps=TAP_OVERSAMPLING, cutoff=FS/2, fs=1/TS_OVERSAMPLING)

# パラメータ値範囲制約条件
#cons = LinearConstraint(np.eye(params.size), np.zeros_like(params), np.full_like(params, np.inf))

# パラメータ最適化を実行
#minimize_rmse = optimize.minimize(rmse_res, params, args=(expdata, indata), method='trust-constr', jac='2-point', hess=BFGS(), constraints= cons, options={"maxiter":MAX_ITER, "verbose":2, "disp":True})
minimize_rmse = optimize.minimize(rmse_res, params, args=(expdata, indata, FrequencyResponse), method='trust-constr', jac='2-point', hess=BFGS(), options={"maxiter":MAX_ITER, "verbose":2, "disp":True})

#print(minimize_rmse)

print(minimize_rmse.x)

plot_fig(indata, expdata, minimize_rmse.x, FrequencyResponse)

#plot_fig(indata, expdata, params)
