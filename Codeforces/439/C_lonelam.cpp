/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const ll moder = 998244353;

typedef long double ld;
ll mod_pow(ll base, ll n) {
  ll ret = 1;
  while (n) {
    if (n & 1) {
      ret *= base;
      ret %= moder;
    }
    base *= base;
    base %= moder;
    n >>= 1;
  }
  return ret;
}
ll fac[10000];
int main() {
  ll a, b, c;
  fac[0] = 1;
  for (ll i = 1; i < 6000; i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= moder;
  }
  while (cin >> a >> b >> c) {
    ll ans = 1, tot = 1, ret = 1;
    for (ll i = min(a, b), j = max(a, b), k = 1; i > 0; i--, j--, k++) {
      ans *= (i * j) % moder;
      ans %= moder;
      tot += ans * mod_pow(fac[k], moder - 2);
      tot %= moder;
    }
    ret *= tot;
    ret %= moder;
    ans = tot = 1;
    for (ll i = min(a, c), j = max(a, c), k = 1; i > 0; i--, j--, k++) {
      ans *= (i * j) % moder;
      ans %= moder;
      tot += ans * mod_pow(fac[k], moder - 2);
      tot %= moder;
    }
    ret *= tot;
    ret %= moder;
    ans = tot = 1;
    for (ll i = min(c, b), j = max(c, b), k = 1; i > 0; i--, j--, k++) {
      ans *= (i * j) % moder;
      ans %= moder;
      tot += ans * mod_pow(fac[k], moder - 2);
      tot %= moder;
    }
    ret *= tot;
    ret %= moder;
    cout << ret << endl;
  }
}
