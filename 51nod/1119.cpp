#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int moder = 1000000007;
const int maxn = 1000000;
const int maxm = maxn * 2 + 20;
int n, m;
int fact[maxm];
ll mod_pow(int x, int n) {
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
  fact[0] = 1;
  for (int i = 1; i < maxm; i++) {
    fact[i] = 1LL * fact[i - 1] * i % moder;
  }
}
void solve() {
  int a = fact[n + m - 2];
  int b = 1LL * fact[n - 1] * fact[m - 1] % moder;
  int ans = 1LL * a * mod_pow(b, moder - 2) % moder;
  printf("%d\n", ans);
}
int main() {
  init();
  while (scanf("%d%d", &n, &m) != EOF) {
    solve();
  }
  return 0;
}
