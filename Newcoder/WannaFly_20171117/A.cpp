/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

ll n, t, x, y, z;
ll check_mul(ll x, ll y) {
  ll p = x*y;
  return !x || p / x == y;
}
ll check_add(ll x, ll y) {
  ll sum = x + y;
  return sum >= x;
}
ll check(ll n) {
  if (n % 2 == 0 && !check_mul(n / 2, n + 1)) return 0;
  if (n & 1 && !check_mul(n, (n + 1)/2)) return 0;

  if (!check_mul(n + 1, x + y)) return 0;
  ll tmp1 = (n + 1) * (x + y);
  ll tmp2 = n * (n + 1);
  if (!check_mul(tmp2, z)) return 0;

  tmp2 *= z;
  tmp2 /= 2;
  if (!check_add(tmp2, tmp1)) return 0;

  return tmp2 + tmp1 < t;
}
void work() {
  ll ans = 0LL;
  
  cin >> n >> t;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> z;
    ll lb = 0LL, ub = 1LL;
    while (1) {
      ll tmp = (ub + 1LL) * (x + y) + ub * (ub + 1LL) / 2LL * z;
      if (tmp > t) {
        break;
      }
      else {
        ub *= 2LL;
      }
    }
    lb = ub / 2LL;
    while (lb  < ub)
    {
      ll mid = (lb + ub) / 2LL;
      if (check(mid)) {
        lb = mid + 1;
      }
      else {
        ub = mid;
      }
    }

    ll k = lb - 1;
    ll S = (k + 1)*(x + y) + (k*(k + 1) / 2)*z;
    ll T = S - (k + 1)*x;
    T += max(t - S - x, 0LL);

    ans += T;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
