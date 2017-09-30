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

ll n;
bool check(ll x, ll y, ll z) {
  ll left = z * (4 * x * y - n * x - n * y);
  ll right = n * x * y;
  if (left == right) return 0;
  if (left > right) return -1;
  if (left < right) return 1;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= 3500; ++i) {
    for (int j = 3500; j >= 1; --j) {
      ll lb = 1, ub = 3500;
      while (lb <= ub) {
        ll mid = (lb + ub) / 2LL;
        ll left = mid * (4LL * i * j - n * i - n * j);
        ll rigt = 1LL * n * i * j;
        if (left > rigt) {
          ub = mid - 1;
        } else if (left < rigt) {
          lb = mid + 1;
        } else {
          printf("%d %d %d\n", i, j, mid);
          return 0;
        }
      }
    }
  }
}
