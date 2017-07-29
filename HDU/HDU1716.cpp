#include <bits/stdc++.h>
using namespace std;
int a[20];
bool used[20];
int vi;
set<int> ans[20];
bool first;
void dfs(int deep) {
  if (deep == 4) {
    ans[vi / 1000].insert(vi);
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (used[i] || (!deep && !a[i])) continue;
    used[i] = true;
    vi = vi * 10 + a[i];
    dfs(deep + 1);
    vi = (vi - a[i]) / 10;
    used[i] = false;
  }
}
void solve(int kase) {
  if (kase) printf("\n");
  first = true;
  vi = 0;
  for (int i = 0; i < 20; ++i) ans[i].clear();
  sort(a, a + 4);
  memset(used, 0, sizeof(used));
  dfs(0);

  for (int i = 0; i < 10; ++i) {
    bool fi = true;
    if (ans[i].size()) {
      for (int x : ans[i]) {
        if (fi) fi = false, printf("%d", x);
        else printf(" %d", x);
      }
      printf("\n");
    }
  }
}
int main() {
  int kase = 0;
  while (scanf("%d%d%d%d", a + 0, a + 1, a + 2, a + 3) != EOF) {
    if (!(a[0] || a[1] || a[2] || a[3])) break;
    solve(kase++);
  }
  return 0;
}
