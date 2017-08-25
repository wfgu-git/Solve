/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int moder = 1000000007;
const int maxn = 8;

struct Matrix {
  int n;
  ll mat[maxn][maxn];
  Matrix(int _n) : n(_n) {}
  void clr() {
    memset(mat, 0, sizeof(mat));
  }
  void unit() {
    clr();
    for (int i = 0; i < n; i++)
      mat[i][i] = 1;
  }
  Matrix operator * (const Matrix &rhs) {
    Matrix ret(n);
    ret.clr();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) if (mat[i][j]) {
        for (int k = 0; k < n; k++) {
          ret.mat[i][k] = (ret.mat[i][k] + mat[i][j] * rhs.mat[j][k] % moder) % moder;
        }
      }
    }
    return ret;
  }
  Matrix operator + (const Matrix &rhs) {
    Matrix ret(n);
    ret.clr();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret.mat[i][j] = (mat[i][j] + rhs.mat[i][j]) % moder;
      }
    }
    return ret;
  }
  Matrix operator - (const Matrix &rhs) {
    Matrix ret(n);
    ret.clr();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret.mat[i][j] = (mat[i][j] - rhs.mat[i][j]) % moder;
      }
    }
    return ret;
  }
  vector< ll > operator * (const vector< ll > &rhs) {
    vector< ll > ret(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret[i] = (ret[i] + mat[i][j] * rhs[j] % moder) % moder;
      }
    }
    return ret;
  }
  Matrix operator ^ (ll b) {
    Matrix ret(n);
    ret.unit();
    Matrix base = *this;
    while (b) {
      if (b & 1)
        ret = ret * base;
      base = base * base;
      b >>= 1;
    }
    return ret;
  }
} ;
ll n, m;
void work() {
  scanf("%lld%lld", &n, &m);
  Matrix raw(2);
  raw.mat[0][0] = 1; raw.mat[0][1] = 2;
  raw.mat[1][0] = 1; raw.mat[1][1] = 0;
  Matrix aid(2);
  if (n & 1) {
    aid.mat[0][0] = 0; aid.mat[0][1] = 2;
    aid.mat[1][0] = 1; aid.mat[1][1] = -1;
  } else {
    aid.unit();
  }
  raw = raw ^ n;
  raw = raw - aid;
  raw = raw ^ (m - 1);
  printf("%lld\n", raw.mat[0][0]);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
