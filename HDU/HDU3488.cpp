#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 20;
const int inf = 0x3f3f3f3f;
int love[maxn][maxn];
int ex_girl[maxn];
int ex_boy[maxn];
bool vis_girl[maxn];
bool vis_boy[maxn];
int match[maxn];
int slack[maxn];
int T, n, m;
bool dfs(int girl) {
  vis_girl[girl] = true;
  for (int boy = 0; boy < n; ++boy) {
    if (vis_boy[boy]) continue;
    int gap = ex_girl[girl] + ex_boy[boy] - love[girl][boy];
    if (gap == 0) {
      vis_boy[boy] = true;
      if (match[boy] < 0 || dfs(match[boy])) {
        match[boy] = girl;
        return true;
      }
    } else {
      slack[boy] = min(slack[boy], gap);
    }
  }
  return false;
}
int KM() {
  memset(match, -1, sizeof(match));
  memset(ex_boy, 0, sizeof(ex_boy));
  for (int i = 0; i < n; ++i) {
    ex_girl[i] = love[i][0];
    for (int j = 1; j < n; ++j) {
      ex_girl[i] = max(ex_girl[i], love[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    memset(slack, 0x3f, sizeof(slack));
    while (true) {
      memset(vis_girl, 0, sizeof(vis_girl));
      memset(vis_boy, 0, sizeof(vis_boy));
      if (dfs(i)) break;
      int d = inf;
      for (int j = 0; j < n; ++j) {
        if (!vis_boy[j]) d = min(d, slack[j]);
      }
      for (int j = 0; j < n; ++j) {
        if (vis_girl[j]) ex_girl[j] -= d;
        if (vis_boy[j]) ex_boy[j] += d;
        else slack[j] -=d;
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += love[match[i]][i];
  }
  return ret;
}
int main() {
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    memset(love, -0x3f, sizeof(love));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
      static int u, v, x;
      scanf("%d%d%d", &u, &v, &x);
      --u, --v;
      love[u][v] = max(love[u][v], -x);
    }
    printf("%d\n", -KM());
  }
  return 0;
}
