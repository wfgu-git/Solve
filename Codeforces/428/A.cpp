#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
int n, k;
int a[maxn];
inline void work() {
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int d = 0;
  while (k > 0 && n) {
    ++d; --n;
    if (a[d] <= 8) {
      k -= a[d];
    } else {
      k -= 8;
      a[d + 1] += (a[d] - 8);
    }
  }
  if (k > 0) printf("%d\n", -1);
  else printf("%d\n", d);
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    work();
  }
  return 0;
}
