import numpy as np
from control.matlab import *
import scipy.optimize as optimize
from scipy import signal
from scipy import interpolate
import matplotlib.pyplot as plt

import os
import csv

PI = np.pi

FS = 44100
N_TAP = 500
KAISER_WINDOW = 30000
OVERSAMPLING_RATIO = 32
TS_OVERSAMPLING = 1 / (FS * OVERSAMPLING_RATIO)

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

# FIRフィルタを設計する
nyq = 0.5 * FS * OVERSAMPLING_RATIO
atten = signal.kaiser_atten(N_TAP,  KAISER_WINDOW / nyq)
beta = signal.kaiser_beta(atten)

params = signal.firwin(N_TAP, 1.6*FS/2, nyq=nyq, window=('kaiser', beta))

fir = FIR_filter(params)

# 実験データCSVを読み込み
with open('impulseResponse_44.1kHz.csv') as f_exp:
    reader = csv.reader(f_exp)
    expdata_read = np.array([row for row in reader]).T
    expdata0 = expdata_read.astype('double')

# 実験データをリサンプリング
f1_x = np.arange(0, 0.0024, TS_OVERSAMPLING).T
f1 = interpolate.interp1d(expdata0[0], expdata0[1], fill_value='extrapolate')
f1_y = f1(f1_x)
f1_y_normalized = f1_y / f1_y.max()
expdata = np.array([f1_x, f1_y_normalized])

# 入力データCSVを読み込み
with open('impulseInput_44.1kHz.csv') as f_input:
    reader = csv.reader(f_input)
    indata_read = np.array([row for row in reader]).T
    indata0 = indata_read.astype('double')

# 入力データをリサンプリング
f2_x = np.arange(0, 0.0024, TS_OVERSAMPLING).T
f2 = interpolate.interp1d(indata0[0], indata0[1], fill_value='extrapolate')
f2_y = f2(f2_x)
f2_y_normalized = f2_y / f2_y.max()
indata = np.array([f2_x, f2_y_normalized])

y = fir.execute_FIR_filter(indata[1])

# Figureを作成する。
fig1 =plt.figure()

# Axesを作成する。
ax1 = fig1.add_subplot(111)

ax1.plot(indata[0], y, label="result")

# グリッドを表示する。
ax1.grid(True, "major", linestyle="-", linewidth=.7)
ax1.grid(True, "minor", "x", linestyle="-", linewidth=.3)

#plt.plot(expdata[0], expdata[1], label = "experiment")
#plt.plot(indata[0], y, label="result")
#plt.plot(input[0], input[1], label="input")

# 周波数応答を算出
w, h = signal.freqz(params, 1.0, 8192) # 8192はグラフの周波数の要素数
amp_dB = 20 * np.log10(np.abs(h))
angles = np.unwrap(np.angle(h))
freq = w * FS * OVERSAMPLING_RATIO

print(params)

# Figureを作成する。
fig2 = plt.figure()

# Axesを作成する。
ax2 = fig2.add_subplot(111)

ax2.plot(freq, amp_dB, 'b')

# x軸を対数目盛に設定する。
ax2.set_xscale('log')

# グリッドを表示する。
ax2.grid(True, "major", linestyle="-", linewidth=.7)
ax2.grid(True, "minor", "x", linestyle="-", linewidth=.3)

# グラフを表示する。
plt.show()

#plt.semilogx(freq, amp_dB, 'b')
#plt.semilogx(omega, angles, 'g')
#plt.grid()

#plt.show()