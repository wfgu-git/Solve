#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  while (~scanf("%d", &T)) {
    for (int cas = 1; cas <= T; ++cas) {
      int n;
      scanf("%d", &n);
      int maxv = -1;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        maxv = max(maxv, x);
      }
      bool flag = true;
      if (sum != n * (n - 1) || maxv > 2 * (n - 1)) {
        flag = false;
      }
      printf("%s\n", flag ? "T" : "F");
    }
  }
  return 0;
}
