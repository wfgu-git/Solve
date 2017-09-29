/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll n, x, y, c;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> x >> y >> c;

  ll lb = 0, ub = n * 2LL, ans = 0;
  while (lb <= ub) {
    ll mid = lb + (ub - lb) / 2;
    if (check(mid)) {
      ans = mid;
      ub = mid - 1;
    } else {
      lb = mid + 1;
    }
  }
  cout << ans << endl;
}
