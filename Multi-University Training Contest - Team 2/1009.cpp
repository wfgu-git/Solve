#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;
int a[maxn];
void work(int kase) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  printf("Case #%d: %d\n", kase, ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
