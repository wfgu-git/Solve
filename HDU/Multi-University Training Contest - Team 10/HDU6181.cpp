/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define INF 1e18
const int N = 100000 + 20;
typedef pair<ll, int> P;
int n, r;
struct Edge {
  int to;
  ll cost;
};
vector<Edge> G[N];
ll dist[N], dist2[N];
void addedge(int u, int v, ll w) {
  G[u].push_back(Edge{v, w});
  G[v].push_back(Edge{u, w});
}
void solve() {
  priority_queue<P, vector<P>, greater<P> > q;
  fill(dist, dist + n, INF);
  fill(dist2, dist2 + n, INF);
  dist[0] = 0;
  q.push(P(0, 0));
  while (!q.empty()) {
    P u = q.top();
    q.pop();
    int v = u.second;
    ll d = u.first;
    if (dist2[v] < d) continue;  //取出的不是次短距离，抛弃
    for (int i = 0; i < G[v].size(); i++) {
      Edge& e = G[v][i];
      ll d2 = d + e.cost;
      if (dist[e.to] > d2)  //更新最短距离
      {
        swap(dist[e.to], d2);
        q.push(P(dist[e.to], e.to));
      }
      if (dist2[e.to] >= d2 && dist[e.to] <= d2)  //更新次短距离
      {
        dist2[e.to] = d2;
        q.push(P(dist2[e.to], e.to));
      }
    }
  }
  printf("%lld\n", dist2[n - 1]);
}
void work() {
  for (int i = 0; i < n; ++i) G[i].clear();

  scanf("%d%d", &n, &r);
  for (int i = 0; i < r; ++i) {
    int u, v;
    ll d;
    scanf("%d%d%lld", &u, &v, &d);
    --u; --v;
    addedge(u, v, d);
  }
  solve();
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
