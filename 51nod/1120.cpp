#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int moder = 10007;
ll n;
ll fact[moder * 2 + 20];
ll rev[moder * 2 + 20];
void init() {
  fact[0] = 1;
  for (int i = 1; i < moder * 2; i++) {
    fact[i] = fact[i - 1] * i % moder;
  }
}
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
ll C(ll n, ll m) {
  ll a = fact[n];
  ll b = 1LL * fact[m] * fact[n - m] % moder;
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
void solve() {
  n = n - 1;
  printf("%lld\n", (((lucas(2 * n, n) + moder - lucas(2 * n, n + 1)) % moder) * 2) % moder);
}
int main() {
  init();
  while (scanf("%lld", &n) != EOF) {
    solve();
  }
  return 0;
}
