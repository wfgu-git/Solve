#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 20;
int a[maxn];
int main() {
  int n;
  int kase = 0;
  while (scanf("%d", &n) != EOF && n) {
    if (kase++) printf("\n");
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      static int x;
      scanf("%d", &x);
      sum += x;
      a[i] = x;
    }
    int ans = 0;
    int mid = sum / n;
    for (int i = 0; i < n; ++i) {
      if (a[i] > mid)
        ans += a[i] - mid;
    }
    printf("%d\n", ans);
  }
  return 0;
}
