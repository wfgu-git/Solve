/*
教练我想打ACM！
*/
#include <stdio.h>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

char grid[maxn][maxn];
int dist[maxn][maxn];
int dir[4][2] = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
void work() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i]);
  }
  int x1, y1, x2, y2;
  scanf("%d%d", &x1, &y1);
  scanf("%d%d", &x2, &y2);
  --x1; --y1; --x2; --y2;
  queue<pair<int, int> > Q;
  memset(dist, -1, sizeof(dist));
  dist[x1][y1] = 0;
  Q.push({x1, y1});
  while (!Q.empty()) {
    pair<int, int> now = Q.front();
    Q.pop();
    int x = now.first;
    int y = now.second;
    for (int i = 0; i < 4; ++i) {
      int tx, ty;
      for (int j = 1; j <= k; ++j) {
        tx = x + dir[i][0] * j;
        ty = y + dir[i][1] * j;
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
        if (grid[tx][ty] == '#') break;
        if (dist[tx][ty] == -1 || dist[tx][ty] > dist[x][y] + 1) {
          dist[tx][ty] = dist[x][y] + 1;
          Q.push({tx, ty});
          if (tx == x2 && ty == y2) {
            goto out;
          }
        }
      }
    }
  }
  out: ;
  printf("%d\n", dist[x2][y2]);
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
