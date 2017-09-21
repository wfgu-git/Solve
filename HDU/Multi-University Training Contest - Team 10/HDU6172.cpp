/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 4;
const int moder = 1000000007;

// tree<pii, null_type, greater<pii>, rb_tree_tag,
// tree_order_statistics_node_update> trees[maxn]; tree<pii, null_type,
// greater<pii>, splay_tree_tag, tree_order_statistics_node_update> trees[maxn];
// tree<pii, null_type, greater<pii>, ov_tree_tag,
// tree_order_statistics_node_update> trees[maxn];

struct Matrix {
  int n;
  ll mat[maxn][maxn];
  Matrix(int _n) : n(_n) { clear(); }
  void clear() { memset(mat, 0, sizeof(mat)); }
  void unit() {
    // clear();
    for (int i = 0; i < n; ++i) {
      mat[i][i] = 1;
    }
  }
  Matrix operator*(const Matrix& rhs) const {
    Matrix ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        if (mat[i][j]) {
          for (int k = 0; k < n; ++k) {
            ret.mat[i][k] =
                (1LL * ret.mat[i][k] + mat[i][j] * rhs.mat[j][k] % moder + moder) %
                moder;
          }
        }
    }
    return ret;
  }
  vector<ll> operator*(const vector<ll>& rhs) {
    vector<ll> ret(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret[i] += (mat[i][j] * rhs[j]) % moder;
        ret[i] %= moder;
      }
    }
    return ret;
  }
  Matrix operator^(ll b) {
    Matrix ret(n);
    ret.unit();
    Matrix base = *this;
    while (b) {
      if (b & 1) {
        ret = ret * base;
      }
      base = base * base;
      b >>= 1;
    }
    return ret;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Matrix raw(3);
  raw.mat[0][0] = 4;
  raw.mat[0][1] = 17;
  raw.mat[0][2] = -12;
  raw.mat[1][0] = 1;
  raw.mat[2][1] = 1;
  vector<ll> col = {1255, 197, 31};

  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    if (n == 2) {
      cout << 31;
    } else if (n == 3) {
      cout << 197;
    } else if (n == 4) {
      cout << 1255;
    } else {
      vector<ll> ans = (raw ^ (n - 4)) * col;
      cout << ans[0];
    }
    cout << endl;
  }
  return 0;
}
