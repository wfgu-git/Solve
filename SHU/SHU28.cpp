#include <bits/stdc++.h>
using namespace std;
typedef vector < int > vec;
typedef vector < vec > mat;
const int inf = 0x3f3f3f3f;
const int maxn = 50;
bool vis[maxn + 1];
int dis[maxn + 1];
void spfa(int start, int n, mat g) {
  fill(dis, dis + n, inf);
  memset(vis, 0, sizeof(vis));
  dis[start] = 0;
  queue < int > q;
  q.push(start);
  vis[start] = true;

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    vis[now] = false;
    for (int i = 0; i < n; i++) {
      if (g[now][i] == -1) continue;
      int d = g[now][i];
      if (dis[now] + d < dis[i]) {
        dis[i] = dis[now] + d;
        if (!vis[i]) {
          q.push(i);
          vis[i] = true;
        }
      }
    }
  }
}
void debug() {
  cout << "!!!" << endl;
}
int main() {
  int n;
  int cas = 0;
  while (scanf("%d", &n) == 1) {
    mat g(n, vec(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        scanf("%d", &x);
        g[i][j] = x;
      }
    }
    int s, t;
    scanf("%d%d", &s, &t);
    --s, --t;
    spfa(s, n, g);
    printf("Case %d\n%d\n", ++cas, dis[t]);
  }
  return 0;
}
