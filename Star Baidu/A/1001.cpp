#include <bits/stdc++.h>
using namespace std;
int n;
inline void work() {
  scanf("%d", &n); --n;
  int ans = 0;
  for (int i = 1; i * i <= n; ++i) {
    if (i * i == n) ++ans;
    else if (n % i == 0) ans += 2;
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
