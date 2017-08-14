#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 20;
int n, k;
double mid;
int a[maxn], b[maxn];
double tmp[maxn];
bool check() {
  for (int i = 0; i < n; ++i) tmp[i] = a[i] - mid * b[i];
  sort(tmp, tmp + n);
  reverse(tmp, tmp + n);
  double ans = 0;
  for (int i = 0; i < n - k; ++i) {
    ans += tmp[i];
  }
  return ans >= 0;
}
inline void work() {
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  double l = 0.0, r = 1.0;
  for (int i = 0; i < 100; ++i) {
    mid = (l + r) / 2.0;
    if (check()) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.0lf\n", l * 100.0);
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF && (n + k)) {
    work();
  }
  return 0;
}
