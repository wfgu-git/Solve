/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 4;
const int moder = 1000000007;

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

  Matrix operator * (const Matrix &rhs) const {
    Matrix ret(n);
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] + moder) % moder;
        }
      }
    }
    return ret;
  }

  vector<long long> operator * (const vector<long long> &rhs) const {
    vector<long long> ret(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret[i] = (ret [i] + mat[i][j] * rhs[j]) % moder;
      }
    }
    return ret;
  }

  Matrix operator ^ (ll b) const {
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
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  Matrix raw(4);
  raw.mat[0][0] = 1; raw.mat[0][1] = 5; raw.mat[0][2] = 1; raw.mat[0][3] = -1;
  raw.mat[1][0] = 1;
  raw.mat[2][1] = 1;
  raw.mat[3][2] = 1;

  vector<ll> col(4), ans(4);
  col = {0, 1, 1, 5};

  ll x;
  while (~scanf("%lld", &x)) {
    Matrix ret = raw ^ (x + 1);
    ans = ret * col;
    printf("%lld\n", ans[0]);
  }
  return 0;
}
