/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> ans(n, 0);

    ordered_set t;
    int x, y;
    int sz = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      ans[t.order_of_key({x, ++sz})]++;
      t.insert({x, sz});
    }
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << '\n';
    }
  }
}
