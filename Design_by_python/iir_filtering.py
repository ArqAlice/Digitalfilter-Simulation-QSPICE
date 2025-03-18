import pickle
import numpy as np
import matplotlib.pyplot as plt

class IIRFilter:
    def __init__(self, a0_, p_array_, q_array_):
        self.a0 = a0_
        self.p_array = np.copy(p_array_)
        self.q_array = np.copy(q_array_)

    def _feedback_filter(self, x, p):
        b1 = -np.real(p) * 2
        b2 = np.real(p * np.conjugate(p))
        y = np.zeros(x.shape[0])
        for i in range(x.shape[0]):
            s = x[i]
            if i - 1 >= 0:
                s += -b1 * y[i - 1]
            if i - 2 >= 0:
                s += -b2 * y[i - 2]
            y[i] = s
        return y

    def _feedforward_filter(self, x, q):
        a1 = -np.real(q) * 2
        a2 = np.real(q * np.conjugate(q))
        y = np.zeros(x.shape[0])
        for i in range(x.shape[0]):
            s = x[i]
            if i - 1 >= 0:
                s += a1 * x[i - 1]
            if i - 2 >= 0:
                s += a2 * x[i - 2]
            y[i] = s
        return y

    def filtering(self, x):
        y = np.copy(x)
        for q in self.q_array:
            y = self._feedforward_filter(y, q)
        for p in self.p_array:
            y = self._feedback_filter(y, p)
        y *= self.a0
        return y

if __name__ == '__main__':
    # サンプリング時間
    T = 0.5

    # サンプリング周波数
    Fs = 200
    t_array = np.arange(0, T, 1/Fs)

    x = np.cos(0.1 * np.pi * Fs * t_array) + \
        np.sin(0.4 * np.pi * Fs * t_array) + \
        np.sin(1.0 * np.pi * Fs * t_array)

    with open('filter_coef_mse100.pickle', 'rb') as f:
        save_dict = pickle.load(f)
    iir = IIRFilter(save_dict['a0'], save_dict['p_array'], save_dict['q_array'])
    y = iir.filtering(x)

    plt.plot(t_array, x, label="origin")
    plt.plot(t_array, y, label="filtered")
    plt.xlabel("t")
    plt.legend()
    plt.savefig("filtered.png")
