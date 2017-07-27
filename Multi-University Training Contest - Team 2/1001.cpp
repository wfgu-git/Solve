#include <bits/stdc++.h>
using namespace std;
const int maxn = 80000 + 20;
char a[maxn];
char b[maxn];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    scanf("%s", a);
    scanf("%s", b);
    int dif = 0, sam = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) ++sam;
      else ++dif;
    }
    int t = min(x, y);
    bool flag = true;
    if (t >= sam) {
      if (dif < x + y - 2 * sam) flag = false;
    } else {
      x -= t; y -=t;
      if (dif < x + y) flag = false;
    }
    if (flag) printf("Not lying\n");
    else printf("Lying\n");
  }
  return 0;
}
