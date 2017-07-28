#include <cstdio>
using namespace std;
// using ll = long long;
typedef long long ll;
ll n, m, p;
ll mod_pow(ll x, ll n) {
  ll ans = 1, base = x % p;
  while (n) {
    if (n & 1)
      ans = ans * base % p;
    base = base * base % p;
    n >>= 1;
  }
  return ans;
}
ll C(ll n, ll m) {
  if (m > n) return 0;
  ll ans = 1;
  for (int i = 1; i <= m; ++i) {
    ll a = (n + i - m) % p;
    ll b = i;
    ans = ans * (a * mod_pow(b, p - 2) % p) % p;
  }
  return ans;
}
ll lucas(ll n, ll m) {
  if (m == 0) return 1;
  return C(n % p, m %p) * lucas(n / p, m / p) % p;
}
void solve() {
  printf("%lld\n", lucas(n, m));
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%lld%lld%lld", &n, &m, &p);
    solve();
  }
  return 0;
}
