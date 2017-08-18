#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
};
int main() {

  return 0;
}
