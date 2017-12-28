struct Complex {
  double r, i;
  Complex(double r = 0, double i = 0) : r(r), i(i){};
  Complex operator+(const Complex &rhs) {
    return Complex(r + rhs.r, i + rhs.i);
  }
  Complex operator-(const Complex &rhs) {
    return Complex(r - rhs.r, i - rhs.i);
  }
  Complex operator*(const Complex &rhs) {
    return Complex(r * rhs.r - i * rhs.i, i * rhs.r + r * rhs.i);
  }
} va[N], vb[N];

//雷德算法--倒位序
void rader(Complex F[],
           int len)  // len = 2^M,reverse F[i] with  F[j] j为i二进制反转
{
  int j = len >> 1;
  for (int i = 1; i < len - 1; ++i) {
    if (i < j) swap(F[i], F[j]);  // reverse
    int k = len >> 1;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}
// FFT实现
void FFT(Complex F[], int len, int t) {
  rader(F, len);
  for (int h = 2; h <= len; h <<= 1)  //分治后计算长度为h的DFT
  {
    Complex wn(cos(-t * 2 * pi / h),
               sin(-t * 2 * pi / h));  //单位复根e^(2*PI/m)用欧拉公式展开
    for (int j = 0; j < len; j += h) {
      Complex E(1, 0);  //旋转因子
      for (int k = j; k < j + h / 2; ++k) {
        Complex u = F[k];
        Complex v = E * F[k + h / 2];
        F[k] = u + v;  //蝴蝶合并操作
        F[k + h / 2] = u - v;
        E = E * wn;  //更新旋转因子
      }
    }
  }
  if (t == -1)  // IDFT
    for (int i = 0; i < len; ++i) F[i].r /= len;
}
