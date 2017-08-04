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
  for (int i = 1; i < moder * 2; i++) {
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
