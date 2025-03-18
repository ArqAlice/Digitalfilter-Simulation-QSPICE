import numpy as np
from control.matlab import *
from control import tf, c2d
from scipy import signal
from scipy import interpolate
import matplotlib.pyplot as plt

import os
import csv

PI = np.pi

FS = 44100
OVERSAMPLING_RATIO = 8
TS_OVERSAMPLING = 1 / (FS * OVERSAMPLING_RATIO)

class IIR_filter:
    def __init__(self, b_, a_):
        self.b = np.copy(b_)
        self.a = np.copy(a_)
    
    def IIR_filter_time_domain(self, n, x):
        y = x
        for i in range(n):
            y = signal.lfilter(self.b, self.a, y)
        return y
    
    def IIR_filter_freq_domain(self, n, fs):
        w, h = signal.freqz(self.b, self.a, fs=fs)
        h_out = h ** n
        return w, h_out

# IIRフィルタを設計する
wp1 = FS * 0.5   # 通過域遮断周波数[Hz]
ws1 = FS * 0.55 # 阻止域遮断周波数[Hz]
gpass1 = 0.5     # 通過域最大損失量[dB]
gstop1 = 50     # 阻止域最小減衰量[dB]
ftype = 'cheby2'# chebyshev2
fs = FS * OVERSAMPLING_RATIO
multiple = 3 # 多段する回数

b, a = signal.iirdesign(wp1, ws1, gpass1, gstop1, output='ba', ftype=ftype, fs=fs)

iir = IIR_filter(b, a)

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

# 時間軸応答を算出
y = iir.IIR_filter_time_domain(multiple, indata[1])

# Figureを作成する。
fig1 =plt.figure()

# Axesを作成する。
ax1 = fig1.add_subplot(111)

ax1.plot(indata[0], y, label="result")

# グリッドを表示する。
ax1.grid(True, "major", linestyle="-", linewidth=.7)
ax1.grid(True, "minor", "x", linestyle="-", linewidth=.3)

# 周波数応答を算出
w, h = iir.IIR_filter_freq_domain(multiple, FS * OVERSAMPLING_RATIO)
amp_dB = 20 * np.log10(np.abs(h))
angles = np.unwrap(np.angle(h))
freq = w

# フィルタ係数を出力
print('filter param:b')
print(b)
print('filter param:a')
print(a)

# Figureを作成する。
fig2 = plt.figure()

# Axesを作成する。
ax2 = fig2.add_subplot(2,1,1)
ax2.plot(freq, amp_dB, 'b')

# グリッドを表示する。
ax2.grid(True, "major", linestyle="-", linewidth=.7)
ax2.grid(True, "minor", "x", linestyle="-", linewidth=.3)

# x軸を対数目盛に設定する。
ax2.set_xscale('log')

ax3 = fig2.add_subplot(2,1,2)
ax3.plot(freq, angles, 'r')

# x軸を対数目盛に設定する。
ax3.set_xscale('log')

# グリッドを表示する。
ax3.grid(True, "major", linestyle="-", linewidth=.7)
ax3.grid(True, "minor", "x", linestyle="-", linewidth=.3)

# グラフを表示する。
plt.show()

#plt.semilogx(freq, amp_dB, 'b')
#plt.semilogx(omega, angles, 'g')
#plt.grid()

#plt.show()