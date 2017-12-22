/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 3;
const int moder = 1e9 + 7;

struct Matrix {
  int n;
  ll mat[maxn][maxn];
  Matrix(int _n) : n(_n) {
    clear();
  }
  void clear() {
    memset(mat, 0, sizeof(mat));
  }
  void unit() {
    for (int i = 0; i < n; ++i) {
      mat[i][i] = 1;
    }
  }

  Matrix operator * (const Matrix & rhs) {
    Matrix ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) if (mat[i][j]) {
        for (int k = 0; k < n; ++k) {
          ret.mat[i][k] = (ret.mat[i][k] + mat[i][j] * rhs.mat[j][k] % moder + moder) % moder;
        }
      }
    }
    return ret;
  }

  vector<ll> operator * (const vector<ll> & rhs) {
    vector<ll> ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret[i] = (ret[i] + mat[i][j] * rhs[j] % moder + moder) % moder;
      }
    }
    return ret;
  }

  Matrix operator ^ (ll b) {
    Matrix ret(n), base = *this;
    ret.unit();
    while (b) {
      if (b & 1) {
        ret = ret * base;
      }
      base = base * base;
      b >>= 1;
    }
    return ret;
  }
} ;
void work() {
  Matrix raw(3);
  raw.mat[0][0] = 4; raw.mat[0][1] = -4; raw.mat[0][2] = 1;
  raw.mat[1][0] = 1; raw.mat[1][1] = 0; raw.mat[1][2] = 0;
  raw.mat[2][0] = 0; raw.mat[2][1] = 0; raw.mat[2][2] = 2;
  vector<ll> col_vec{1LL, 0LL, 2LL};
  ll n;
  cin >> n;
  if (n < 3) {
    cout << (n == 1 ? 0 : 1);
    return;
  }
  raw = raw ^ (n - 2);
  vector<ll> ans;
  ans = raw * col_vec;
  cout << ans[0];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
