/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

int n, m1, m2, L;
struct Edge {
  int from, to, dist, next;
} edge1[50 * 2 + 1], edge2[maxn * maxn];
int head1[maxn], head2[maxn];
int tot1, tot2;
int dist[maxn][55];
bool vis[maxn][55];
void add_edge(int from, int to, int dist, int tag) {
  if (tag) {
    edge1[tot1] = {from, to, 1, head1[from]};
    head1[from] = tot1++;
  } else {
    edge2[tot2] = {from, to, dist, head2[from]};
    head2[from] = tot2++;
  }
}
void SPFA() {
  queue<pair<int, int> > Q;
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  Q.push({1, 0});
  dist[1][0] = 0;
  vis[1][0] = 1;
  while (!Q.empty()) {
    pair<int, int> now = Q.front();
    Q.pop();
    int u = now.first;
    int cont = now.second;
    vis[u][cont] = 0;
    if (cont < m1) {
      for (int i = head1[u]; i != -1; i = edge1[i].next) {
        int v = edge1[i].to;
        int w = edge1[i].dist;
        if (dist[v][cont + 1] > dist[u][cont] + w) {
          dist[v][cont + 1] = dist[u][cont] + w;
          if (!vis[v][cont + 1]) vis[v][cont + 1] = 1;
          Q.push({v, cont + 1});
        }
      }
    }
    for (int i = head2[u]; i != -1; i = edge2[i].next) {
      int v = edge2[i].to;
      int w = edge2[i].dist;
      if (dist[v][cont] > dist[u][cont] + w) {
        dist[v][cont] = dist[u][cont] + w;
        if (!vis[v][cont]) vis[v][cont] = 1;
        Q.push({v, cont});
      }
    }
  }
}
void work() {
  int T;
  cin >> T;
  while (T--) {
    tot1 = tot2 = 0;
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));

    cin >> n >> m1 >> m2 >> L;
    for (int i = 0; i < m1; ++i) {
      int x, y;
      cin >> x >> y;
      add_edge(x, y, 1, 1);
      add_edge(y, x, 1, 1);
    }
    for (int i = 0; i < m2; ++i) {
      int x, y, c;
      cin >> x >> y >> c;
      add_edge(x, y, c, 0);
      add_edge(y, x, c, 0);
    }
    SPFA();
    int ans = inf;
    for (int i = 0; i <= m1; ++i) {
      if (dist[n][i] <= L) {
        ans = min(ans, dist[n][i] -  i);
      }
    }
    if (ans > 1e8) ans = -1;
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
