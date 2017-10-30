/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll a[maxn];
void work() {
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  ll ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans += sum;
    sum -= a[i];
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  // #ifndef ONLINE_JUDGE
  //   freopen("data.in", "r", stdin);
  // #endif

  work();
}
