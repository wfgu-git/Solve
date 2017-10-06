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

ll fac[5000 + 20];
ll mod_pow(ll x, ll n) {
  ll ans = 1, base = x;
  while (n) {
    if (n & 1) {
      ans = ans * base % moder;
    }
    base = base * base % moder;
    n >>= 1;
  }
  return ans;
}
ll solve(ll a, ll b) {
  ll x = min(a, b);
  ll y = max(a, b);
  ll ret = 0;
  for (int i = 0; i <= min(a, b); ++i) {
    ll tmp = 1;
    tmp = tmp * fac[x] % moder * fac[y] % moder;
    tmp %= moder;
    tmp = tmp * mod_pow(fac[x - i], moder - 2) % moder;
    tmp = tmp * mod_pow(fac[y - i], moder - 2) % moder;
    tmp = tmp * mod_pow(fac[i], moder - 2) % moder;
    ret = (ret + tmp) % moder;
  }
  return ret;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i <= 5000; ++i) {
    fac[i] = fac[i - 1] * i % moder;
  }
  int a, b, c;
  cin >> a >> b >> c;
  ll ret = 1;
  ret *= solve(a, b); ret %= moder;
  ret *= solve(a, c); ret %= moder;
  ret *= solve(b, c); ret %= moder;
  cout << ret;
}
