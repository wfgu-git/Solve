#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int moder = 1000000007;
ll mod_pow(ll x, ll n) {
  ll ans = 1, base = x % moder;
  while (n) {
    if (n & 1)
      ans = ans * base % moder;
    base = base * base % moder;
    n >>= 1;
  }
  return ans;
}
ll n, k;
int main() {
  int kase = 0;
  while (scanf("%lld%lld", &n, &k) != EOF) {
    printf("Case #%d: %lld\n", ++kase, mod_pow(n, k));
  }
  return 0;
}
