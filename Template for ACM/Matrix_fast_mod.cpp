#include <bits/stdc++.h>
using namespace std;
const int moder = 3;
const int maxn = 8;
struct Matrix
{
  int n;
  long long mat[maxn][maxn];
  Matrix(int _n) : n(_n) {
    clear();
  }
  void clear() {memset(mat, 0, sizeof(mat));}
  void unit() {
    clear();
    for (int i = 0; i < n; i++) {
      mat[i][i] = 1;
    }
  }

  Matrix operator + (const Matrix &rhs) const {
    Matrix ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret.mat[i][j] = (mat[i][j] + rhs.mat[i][j]) % moder;
      }
    }
    return ret;
  }
  Matrix operator - (const Matrix &rhs) const {
    Matrix ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret.mat[i][j] = (mat[i][j] - rhs.mat[i][j]) % moder;
      }
    }
    return ret;
  }

  Matrix operator * (const Matrix &rhs) {
    Matrix ret(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) if (mat[i][j]) {
        for (int k = 0; k < n; k++) {
          ret.mat[i][k] = (1LL * ret.mat[i][k] + mat[i][j] * rhs.mat[j][k] % moder) % moder;
        }
      }
    }
    return ret;
  }

  vector<long long> operator * (const vector<long long> &rhs) {
    vector<long long> ret(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret[i] += (mat[i][j] * rhs[j]) % moder;
        ret[i] %= moder;
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
