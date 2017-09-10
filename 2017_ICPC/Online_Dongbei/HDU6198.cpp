/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
// const int maxn = 100000 + 20;

const int moder = 998244353;
const int maxn = 2;
struct Matrix
{
  int n;
  long long mat[maxn][maxn];
  Matrix(int _n) : n(_n) {
    clear();
  }
  inline void clear() {memset(mat, 0, sizeof(mat));}
  inline void unit() {
    clear();
    for (int i = 0; i < n; i++) {
      mat[i][i] = 1;
    }
  }

  Matrix operator + (const Matrix &rhs) {
    Matrix ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret.mat[i][j] = (mat[i][j] + rhs.mat[i][j]) % moder;
      }
    }
    return ret;
  }
  Matrix operator - (const Matrix &rhs) {
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
          ret.mat[i][k] = (1LL * ret.mat[i][k] + (mat[i][j] * rhs.mat[j][k]) % moder) % moder;
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

  Matrix operator ^ (int b) {
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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Matrix raw(2);
  raw.mat[0][0] = 1; raw.mat[0][1] = 1;
  raw.mat[1][0] = 1; raw.mat[1][1] = 0;
  int k;
  while (cin >> k) {
    k += 2;
    Matrix ret = raw ^ (2 * k - 1) - 1;
    cout << ret.mat[0][0] - 1 << endl;
  }
  return 0;
}
