/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll lcm(ll a, ll b) {
  ll g = __gcd(a, b);
  return a / g * b;
}
void work() {
  int a, b, c;
  cin >> a >> b >> c;
  ll ans = lcm(a, lcm(b, c));
  cout << ans;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
