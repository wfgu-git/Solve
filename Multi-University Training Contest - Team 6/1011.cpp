#include <bits/stdc++.h>
using namespace std;
int n;
int a, b, c, ab, ac, bc, abc;
void work(int kase) {
  int tmp = -1;
  int ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &ab, &bc, &ac, &abc);
    ab -= abc;
    bc -= abc;
    ac -= abc;
    a -= ab + ac + abc;
    b -= ab + bc + abc;
    c -= ac + bc + abc;
    if (a < 0 || b < 0 || c < 0 || ab < 0 || bc < 0 || ac < 0 || abc < 0) continue;
    tmp = a + b + c + ab + ac + bc + abc;
    ans = max(tmp, ans);
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
