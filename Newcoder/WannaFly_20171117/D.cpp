/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200000 + 20;

int n;
ll x, y;
ll a[maxn], b[maxn], t;
bool check(ll x) {
  for (int i = 0; i < n; ++i) {
    if (a[i] + x < b[i]) {
      return 0;
    }
  }
  return 1;
}
void work() {
  scanf("%d%lld%lld", &n, &x, &y);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", b + i);
  }
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < x; ++i) {
    if (a[i] >= y) break;
    if (a[i] < y) {
      a[i] = y;
    }
  }
  sort(a, a + n);
  ll lb = 0, ub = INT_MAX;
  while (lb <= ub) {
    ll mid = lb + (ub - lb) / 2;
    if (check(mid)) {
      t = mid;
      ub = mid - 1;
    } else {
      lb = mid + 1;
    }
  }
  printf("%lld\n", t);
}
int main() {
  // freopen("data.in", "r", stdin);
  work();
}
