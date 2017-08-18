#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
int a[maxn];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n, K;
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    reverse(a, a + n);
    int ans = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i - 1] - a[i] > K) {
        break;
      }
      ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
