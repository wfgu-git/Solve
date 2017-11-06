/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 53000 + 20;

struct Edge {
  int to, next;
  ll dist;
} edge[maxn * 2];
int head[maxn];
int n, m;
ll fly[22][maxn];
ll dist[maxn];
int inq[maxn];
ll cum[maxn];
void add_edge(int u, int v, ll w) {
  static int cont = 0;
  edge[cont].to = v;
  edge[cont].dist = w;
  edge[cont].next = head[u];
  head[u] = cont++;
}
void SPFA(int id, int s) {
  for (int i = 1; i <= n; ++i) {
    inq[i] = 0;
    dist[i] = inf;
  }
  queue<int> Q;
  Q.push(s);
  inq[s] = 1;
  dist[s] = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    inq[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
      int v = edge[i].to;
      ll w = edge[i].dist;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        if (!inq[v]) {
          Q.push(v);
          inq[v] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    fly[id][i] = dist[i];
  }
}
void work() {
  memset(head, -1, sizeof(head));
  cin >> n >> m;
  ll d;
  cum[1] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> d;
    cum[i + 1] = cum[i] + d;
    add_edge(i, i + 1, d);
    add_edge(i + 1, i, d);
  }
  cin >> d;
  add_edge(1, n, d);
  add_edge(n, 1, d);
  cum[0] = cum[n] + d;

  vector<pair<int, int> > exedges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v >> d;
    add_edge(u, v, d);
    add_edge(v, u, d);
    exedges.push_back({u, v});
  }
  for (int i = 0; i < m; ++i) {
    int u = exedges[i].first;
    int v = exedges[i].second;
    SPFA(i, u);
    SPFA(i, v);
  }
  int q;
  cin >> q;
  while (q--) {
    ll ans = inf;
    int u, v;
    cin >> u >> v;
    ans = abs(cum[u] - cum[v]);
    ans = min(ans, cum[0] - ans);
    for (int i = 0; i < m; ++i) {
      ans = min(ans, fly[i][u] + fly[i][v]);
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
