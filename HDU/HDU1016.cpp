#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 20;
int n;
bool vis[maxn];
int prime[maxn];
int notprime[maxn] = {1, 1};
void init() {
  int tot = 0;
  for (int i = 2; i <= maxn; ++i) {
    if (!notprime[i]) prime[++tot] = i;
    for (int j = 1; j <= tot && i * prime[j] <= maxn; ++j) {
      notprime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
vector<int> vi;
void dfs(int deep) {
  if (deep == n - 1) {
    if (notprime[vi.front() + vi.back()]) return;
    bool first = true;
    for (int x : vi) {
      if (first) printf("%d", x), first = false;
      else printf(" %d", x);
    }
    printf("\n");
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (!vis[i] && !notprime[vi.back() + i]) {
      vis[i] = true;
      vi.push_back(i);
      dfs(deep + 1);
      vi.pop_back();
      vis[i] = false;
    }
  }
}
void solve(int kase) {
  printf("Case %d:\n", kase);
  memset(vis, 0, sizeof(vis));
  vi.clear();
  vi.push_back(1);
  vis[1] = true;
  dfs(0);
  printf("\n");
}
int main() {
  init();
  int kase = 0;
  while (scanf("%d", &n) != EOF) {
    solve(++kase);
  }
  return 0;
}
