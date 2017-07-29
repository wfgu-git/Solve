#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a, b, c, d;
ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll g = extend_gcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}
void solve() {
  if (a == 1) {
    printf("1/%d\n", b - 1);
  } else {
    ll x, y;
    ll d = extend_gcd(a, b, x, y);
    if (d != 1) {
      printf("%lld/%lld\n", (ll)a / d, (ll)b / d);
    } else {
      ll c1 = (-y + a) % a;
      ll c2 = (y + a) % a;
      ll d1 = (x + b) % b;
      ll d2 = (-x + b) % b;
      if (d1 < d2) {
        d1 = d2;
        c1 = c2;
      }
      printf("%lld/%lld\n", c1, d1);
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d/%d", &a, &b);
    solve();
  }
  return 0;
}
