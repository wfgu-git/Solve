/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int a[maxn];
__gnu_pbds::tree<pii, __gnu_pbds::null_type, greater<pii>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> Set;
void work() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  reverse(a, a + n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 10; j <= 1000000000; j *= 10) {
      if (j <= a[i]) continue;
      ans += Set.order_of_key(make_pair(j - a[i], -1));
    }
    Set.insert(make_pair(a[i], i));
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  freopen("data.in", "r", stdin);
  work();
}
