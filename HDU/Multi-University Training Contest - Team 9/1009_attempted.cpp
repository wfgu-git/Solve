/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int limit = 320000;
const int moder = 1e9 + 7;
const long maxn = 1e6 + 20;

int prime[maxn], num_prime = 0;
int nprime[maxn] = {1, 1};
void get_prime() {
  for (int i = 2; i < maxn; ++i) {
    if (!nprime[i]) prime[++num_prime] = i;
    for (int j = 1; j <= num_prime && i * prime[j] < maxn; ++j) {
      nprime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
bool is_prime(ll x) {
  int m = sqrt(1.0 * x);
  for (int i = 2; i <= m; ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
void print(int kase, ll ret) {
  printf("Case #%d: %lld\n", kase, ret);
}


void work(int kase) {
  ll l, r, k;
  scanf("%lld%lld%lld", &l, &r, &k);
  if (!is_prime(k) || k > r) {
    print(kase, 0LL);
  } else if (k > limit) {
    ll ans = 0;
    if (l <= k && k <= r) ans = k % moder;
    print(kase, ans);
  } else {
    ll ans = (dfs(k, 1, r, 0) - dfs(k, 1, l - 1, 0) + moder) % moder;
    print(kase, ans);
  }
}
int main() {
  get_prime();
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
