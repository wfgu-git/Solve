ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll d = extend_gcd(b, a % b, x, y);
  ll t = x; x = y; y = t - a / b * y;
  return d;
}

int crt(int *a, int *m, int n) {
  int M = 1;
  for (int i = 0; i < n; i++) M *= m[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    int Mi = M / m[i];
    extend_gcd(Mi, m[i], x, y);
    ans = (ans + Mi * x * a[i]) % M;
  }
  if (ans < d) ans += M;
  return ans;
}
