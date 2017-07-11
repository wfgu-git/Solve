#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
const int inf = INT_MAX;
const int maxn = 1e5;
int n, c;
int a[maxn + 1];
bool check(int d) {
  int used = 0;
  for (int i = 1; i < c; ++i) {
    int cur = used + 1;
    while (cur < n && a[cur] - a[used] < d) ++cur;
    if (cur == n) return false;
    used = cur;
  }
  return true;
}
int main() {
  while (scanf("%d%d", &n, &c) == 2) {
    // for_each(a, a + n, [] (int &x) {scanf("%d", &x);});
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int lb = 0, ub = inf;
    while (ub - lb > 1) {
      int mid = lb + (ub - lb) / 2;
      if (check(mid)) lb = mid;
      else ub = mid;
    }
    printf("%d\n", lb);
  }
  return 0;
}
