#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300 +20;
int love[maxn][maxn];
int lx[maxn], ly[maxn];
bool used_x[maxn], used_y[maxn];
int match[maxn];
int slack[maxn];
int n;
bool dfs(int x) {
  used_x[x] = true;
  for (int y = 0; y < n; ++y) {
    if (used_y[y]) continue;
    int d = lx[x] + ly[y] - love[x][y];
    if (d == 0) {
      used_y[y] = true;
      if (match[y] == -1 || dfs(match[y])) {
        match[y] = x;
        return true;
      }
    } else {
      slack[y] = min(slack[y], d);
    }
  }
  return false;
}
int KM() {
  memset(match, -1, sizeof(match));
  memset(ly, 0, sizeof(ly));
  for (int i = 0; i < n; ++i) {
    lx[i] = love[i][0];
    for (int j = 1; j < n; ++j) {
      lx[i] = max(lx[i], love[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    fill(slack, slack + n, inf);
    while (true) {
      memset(used_x, 0, sizeof(used_x));
      memset(used_y, 0, sizeof(used_y));
      if (dfs(i)) break;
      int d = inf;
      for (int j = 0; j < n; ++j) {
        if (!used_y[j]) d = min(d, slack[j]);
      }
      for (int j = 0; j < n; ++j) {
        if (used_x[j]) lx[j] -= d;
        if (used_y[j]) ly[j] += d;
        else slack[j] -= d;
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
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &love[i][j]);
      }
    }
    printf("%d\n", KM());
  }
  return 0;
}
