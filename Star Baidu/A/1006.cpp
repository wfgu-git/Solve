#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
int n, m;
char grid[maxn][maxn];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
inline bool inside(const int& x, const int& y) {
  if (x < 0 || x > n + 1 || y < 0 || y > m + 1) return false;
  return true;
}
void dfs(int x, int y, int tag) {
  grid[x][y] = '@';
  for (int d = 0; d < 4; ++d) {
    int tx = x + dx[d];
    int ty = y + dy[d];
    if (inside(tx, ty) && grid[tx][ty] == '0' + tag) {
      dfs(tx, ty, tag);
    }
  }
}
inline void work() {
  for (int i = 1; i <= n; ++i) {
    scanf("%s", grid[i] + 1);
  }
  for (int c = 0; c <= m + 1; ++c) {grid[0][c] = '0'; grid[n + 1][c] = '0';}
  for (int r = 0; r <= n + 1; ++r) {grid[r][0] = '0'; grid[r][m + 1] = '0';}
  int cnt0, cnt1;
  cnt0 = cnt1 = 0;
  for (int i = 0; i <= n + 1; ++i) {
    for(int j = 0; j <= m + 1; ++j) {
      if (grid[i][j] == '0') {
        ++cnt0;
        dfs(i, j, 0);
      } else if (grid[i][j] == '1') {
        ++cnt1;
        dfs(i, j, 1);
      }
    }
  }
  if (cnt0 == 2 && cnt1 == 1) printf("0\n");
  else if (cnt1 == 1 && cnt0 == 1) printf("1\n");
  else printf("-1\n");
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    work();
  }
  return 0;
}
