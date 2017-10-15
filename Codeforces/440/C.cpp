/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll d = extend_gcd(b, a % b, x, y);
  ll t = x; x = y; y = t - a / b * y;
  return d;
}
ll x;
int main() {
#ifndef ONLINE_JUDGE
  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> x;
    int ans = 0;
    if (x == 9) {
      cout << 1 << endl;
      continue;
    }
    if (x < 3) {
      cout << -1 << endl;
      continue;
    }
    if (x & 1) {
      x -= 9;
      if (x < 3) {
        cout << -1 << endl;
        continue;
      }
      ans++;
    }
    // ll x0, y0;
    // extend_gcd(4, 6, x0, y0);
    if (x % 4 == 2) {
      x -= 6;
      ans++;
    }
    ans += x / 4;
    cout << ans << endl;
  }
}
