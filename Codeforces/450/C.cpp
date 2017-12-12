/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

vector<int> a;
int dp[maxn][25];
__gnu_pbds::tree<int, __gnu_pbds::null_type, greater<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> Set;

struct RMQ {
  void init(const vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) dp[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 0; i + (1 << j) -1 < n; ++i) {
        dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  // [l, r]
  int query(int l, int r) {
    // // int k = 0;
    // while ((1 << k + 1) <= r - l + 1) ++k;
    int k = log(r - l + 1) / log(2.0);
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
  }
} rmq;
void work() {
  int n;
  cin >> n;
  a.resize(n);
  a.clear();
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  rmq.init(a);

  int mn, l = 0, ans = a[0];
  for (int i = 0; i < n; ++i) {
    int k = Set.order_of_key(a[i]);
    Set.insert(a[i]);
    // cout << "now is " << a[i] << "  rank = " << k << endl;
    if (k <= 1) {
      if (k == 0) l = i + 1;
      else l = i;
      int fi = *Set.find_by_order(0);
      // cout << "fi = " << fi << endl;
      if (fi == a[i]) {
        if (i + 1 >= n) {
          mn = 1;
        }
        else {
          mn = rmq.query(i + 1, n - 1);
        }
        // cout << "min = " << mn << endl;
        ans = mn;
      } else {
        ans = fi;
      }
    }
  }
  if (l == 1 && ans == a[0] && a[0] != 1) {
    ans = 1;
  }
  cout << ans << endl;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
