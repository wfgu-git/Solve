/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 100 + 20;

int n;
int c1, c2;
int w[maxn];
int ans[maxn], vis[maxn];
int ret, sum;
void dfs(int pos, int left, int tot) {
  if (pos == n) {
    if (tot > ret) {
      ret = tot;
      for (int i = 0; i < n; ++i) {
        ans[i] = vis[i];
      }
    }
    return;
  }
  if (left >= w[pos]) {
    vis[pos] = 1;
    dfs(pos + 1, left - w[pos], tot + w[pos]);
    vis[pos] = 0;
  }
  dfs(pos + 1, left, tot);
}
int main() {
  int kase = 0;
  while (~scanf("%d", &n)) {
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    printf("Case %d\n", ++kase);
    sum = ret = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", w + i);
      sum += w[i];
    }
    scanf("%d%d", &c1, &c2);
    dfs(0, c1, 0);
    // printf("ret = %d   sum = %d\n", ret, sum);
    if (sum - ret > c2) {
      puts("No");
      continue;
    }
    printf("%d ", ret);
    for (int i = 0; i < n; ++i) {
      printf("%d", ans[i]);
    }
    puts("");
  }
}
