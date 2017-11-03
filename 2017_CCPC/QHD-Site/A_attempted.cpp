/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int a[maxn];
ll t[maxn];
void work() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    ll sum = 0;
    for (int i = 0; i < q; ++i) {
      cin >> x >> y;
      int r = y % m;
      t[i] = (a[x] - 1 - r + m) % m;
      sum += t[i];
    }
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < q; ++i) {
      ans = min(ans, sum + i * m - t[i] * q);
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
