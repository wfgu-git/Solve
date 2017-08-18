#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll moder = 1000000007;
ll dp[10000 + 20];
ll mod_pow(ll x, int n) {
  ll base = x, ret = 1;
  while (n) {
    if (n & 1)
      ret = ret * base % moder;
    base = base * base % moder;
    n >>= 1;
  }
  return ret;
}
void getdp() {
  dp[1] = 1; dp[2] = 6;
  for (int i = 3; i <= 10000 + 2; ++i) {
    dp[i] = 2LL * dp[i - 1] % moder + 4LL * dp[i - 2] % moder + mod_pow(2, i - 1);
    dp[i] %= moder;
  }
}
int N;
void work() {
  scanf("%d", &N);
  if (N == 1) {
    printf("2\n");
    return;
  }
  ll ans = 0;
  for (int i = 2; i <= N - 1; ++i) {
    ans += mod_pow(2, i - 1) * 2LL * dp[N - i] * 2LL % moder;
    ans %= moder;
  }
  ans = ans * 2 % moder;
  ans += 4 * dp[N] % moder;
  ans %= moder;
  printf("%lld\n", ans);
}
int main() {
  getdp();
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
