/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
unsigned long long ull;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a, b;
  cin >> a >> b;
  ll dist = b - a;
  ll ans;
  if (dist >= 10) {
    ans = 0;
  } else {
    ans = 1;
    for (ll i = a + 1; i <= b; ++i) {
      ans *= (i % 10);
      if (!ans) break;
    }
  }
  cout << ans % 10;
}
