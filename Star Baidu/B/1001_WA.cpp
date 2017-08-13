#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int moder = 1000000007;
const int maxn = 1500;
int fac[maxn], inv[maxn];
ll mod_pow(ll x, ll n) {
  ll ans = 1, base = x;
  while (n) {
    if (n & 1)
      ans = ans * base % moder;
    base = base * base % moder;
    n >>= 1;
  }
  return ans;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i < 1500; i++) {
    fac[i] = fac[i - 1] * i % moder;
    inv[i] = mod_pow(fac[i], moder - 2);
  }
}
ll C(ll n, ll m) {
  ll a = fac[n];
  ll b = 1LL * fac[m] * fac[n - m] % moder;
  ll ans = 1LL * a * mod_pow(b, moder - 2) % moder;
  return ans;
}
ll lucas(ll n, ll m) {
  if (n < m) return 0;
  if (n < moder && m < moder) {
    return C(n, m);
  }
  return C(n % moder, m % moder) * lucas(n / moder, m / moder) % moder;
}
int N, M;
inline void work() {
  scanf("%d%d", &N, &M);
  int n = max(N, M);
  int r = min(N, M);
  printf("%lld\n", lucas(n, r));
}
int main() {
  init();
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
