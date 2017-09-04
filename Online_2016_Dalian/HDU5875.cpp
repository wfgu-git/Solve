#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int a[maxn + 2];
int R[maxn + 2];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      R[i] = i;
    }
    for (int i = n - 1; i >= 1; i--) {
      int now = i;
      while (now <= n - 1 && a[i] < a[now + 1]) now = R[now + 1];
      R[i] = now;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      int ans = a[l];
      int now = R[l] + 1;
      while (ans && now <= r) {
        ans %= a[now];
        now = R[now] + 1;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
