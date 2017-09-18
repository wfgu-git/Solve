/*
教练我要打ACM!
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

#include <complex>
typedef complex<double> Complex;
const long double PI = acos(0.0) * 2.0;
// Cooley-Tukey的FFT算法，迭代实现。inverse = false时计算逆FFT
void FFT(vector<Complex> &a, bool inverse) {
  int n = a.size();
  // 原地快速bit reversal
  for(int i = 0, j = 0; i < n; i++) {
    if(j > i) swap(a[i], a[j]);
    int k = n;
    while(j & (k >>= 1)) j &= ~k;
    j |= k;
  }

  double pi = inverse ? -PI : PI;
  for(int step = 1; step < n; step <<= 1) {
    // 把每相邻两个“step点DFT”通过一系列蝴蝶操作合并为一个“2*step点DFT”
    double alpha = pi / step;
    // 为求高效，我们并不是依次执行各个完整的DFT合并，而是枚举下标k
    // 对于一个下标k，执行所有DFT合并中该下标对应的蝴蝶操作，即通过E[k]和O[k]计算X[k]
    // 蝴蝶操作参考：http://en.wikipedia.org/wiki/Butterfly_diagram
    for(int k = 0; k < step; k++) {
      // 计算omega^k. 这个方法效率低，但如果用每次乘omega的方法递推会有精度问题。
      // 有更快更精确的递推方法，为了清晰起见这里略去
      Complex omegak = exp(Complex(0, alpha*k));
      for(int Ek = k; Ek < n; Ek += step << 1) { // Ek是某次DFT合并中E[k]在原始序列中的下标
        int Ok = Ek + step; // Ok是该DFT合并中O[k]在原始序列中的下标
        Complex t = omegak * a[Ok]; // 蝴蝶操作：x1 * omega^k
        a[Ok] = a[Ek] - t;  // 蝴蝶操作：y1 = x0 - t
        a[Ek] += t;         // 蝴蝶操作：y0 = x0 + t
      }
    }
  }

  if(inverse)
    for(int i = 0; i < n; i++) a[i] /= n;
}

// 用FFT实现的快速多项式乘法
void operator * (const vector<double>& v1, const vector<double>& v2) {
  int s1 = v1.size(), s2 = v2.size(), S = 2;
  while(S < s1 + s2) S <<= 1;
  vector<Complex> a(S,0), b(S,0); // 把FFT的输入长度补成2的幂，不小于v1和v2的长度之和
  for(int i = 0; i < s1; i++) a[i] = v1[i];
  FFT(a, false);
  for(int i = 0; i < s2; i++) b[i] = v2[i];
  FFT(b, false);
  for(int i = 0; i < S; i++) a[i] *= b[i];
  FFT(a, true);
  vector<int> res(S + 1);
  for(int i = 0; i < S; i++) {
    res[i] = a[i].real() + 0.5; // 虚部均为0
  }
  for (int i = 0; i < S; ++i) {
    res[i + 1] += res[i] / 10;
    res[i] %= 10;
  }
  int bound = 0;
  for (int i = S - 1; i >= 0; --i) {
    if (res[i]) {
      bound = i;
      break;
    }
  }
  for (int i = bound; i >= 0; --i) {
    putchar('0' + res[i]);
  }
  puts("");
}
char s1[maxn];
char s2[maxn];
vector<double> a, b;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/solve/data.out", "w", stdout);

  while (scanf("%s", s1) != EOF) {
    scanf("%s", s2);
    a.clear(); b.clear();
    int n = strlen(s1);
    for (int i = 0; i < n; ++i) {
      a.push_back((double)(s1[n - i - 1] - '0'));
    }
    n = strlen(s2);
    for (int i = 0; i < n; ++i) {
      b.push_back((double)(s2[n - i - 1] - '0'));
    }
    a * b;
  }
}
