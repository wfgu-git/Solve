/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll moder = (ll)(1e9 + 7);

ll mod_pow(ll a, ll b) {
  ll ret = 1, base = a;
  while (b > 0) {
    if (b & 1) {
      ret = ret * base % moder;
    }
    base = base * base % moder;
    b >>= 1;
  }
  return ret;
}
void work() {
  ll p, m;
  cin >> p >> m;
  ll N = mod_pow(p, m);
  ll ans = (N - p) * mod_pow(p - 1, moder - 2) % moder;
  ans = ans - m + 1 + moder;
  ans %= moder;
  ans *= (N + 2) * mod_pow(2, moder - 2) % moder;
  ans %= moder;
  ans = (ans + m) % moder;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
