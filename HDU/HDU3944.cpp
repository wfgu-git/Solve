#include <bits/stdc++.h>
using namespace std;
const int maxp = 10000 + 20;
int tot, prime[1500], not_prime[maxp] = {1, 1};
int mp[maxp];
int fac[1500][maxp], inv[1500][maxp];
using ll = long long;
ll mod_pow(int x, int n, int moder) {
  ll ans = 1, base = x % moder;
  while (n) {
    if (n & 1)
      ans = ans * base % moder;
    base = base * base % moder;
    n >>= 1;
  }
  return ans;
}
void init() {
  tot = 0;
  for (int i = 2; i < maxp; ++i) {
    if (!not_prime[i]) prime[++tot] = i;
    for (int j = 1; j <= tot && i * prime[j] < maxp; ++j) {
      not_prime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  for (int i = 1; i <= tot; ++i) {
    int k = prime[i];
    mp[k] = i;
    fac[i][0] = fac[i][1] = 1;
    inv[i][0] = inv[i][1] = 1;
    for (int j = 2; j < k; ++j) {
      fac[i][j] = fac[i][j - 1] * j % k;
      inv[i][j] = mod_pow(fac[i][j], k - 2, k);
      if (inv[i][j] < 0) inv[i][j] += k;
    }
  }
}
int C(int n, int m, int p) {
  if (m > n) return 0;
  return 1LL * fac[mp[p]][n] * inv[mp[p]][n - m] * inv[mp[p]][m] % p;
}
int lucas(int n, int r, int p) {
  if (n < p && r < p) {
    return C(n, r, p);
  }
  return C(n % p, r % p, p) * lucas(n / p, r / p, p);
}
int n, m, p;
void solve(int kase) {
  if (m > n / 2) m = n - m;
  int ans = (lucas(n + 1, m, p) + (n - m)) % p;
  printf("Case #%d: %d\n", kase, ans);
}
int main() {
  int kase = 0;
  init();
  while (scanf("%d%d%d", &n, &m, &p) != EOF) {
    solve(++kase);
  }
  return 0;
}
