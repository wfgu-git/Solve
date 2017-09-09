/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll inf = 1e18;
const int maxn = 100000 + 20;

struct Edge {
  int from, to, cap, flow;
  ll cost;
} ;
struct MCMF {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];
  ll d[maxn];
  int p[maxn];
  ll a[maxn];

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i) G[i].clear();
    edges.clear();
  }

  void add_edge(int from, int to, int cap, ll cost) {
    edges.push_back((Edge) {from, to, cap, 0, cost});
    edges.push_back((Edge) {to, from, 0, 0, -cost});
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool SPFA(int s, int t, int& flow, ll& cost) {
    for (int i = 0; i < n; ++i) d[i] = inf;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = inf;

    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = 0;
      for (int i = 0; i < (int)G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.cap > e.flow && d[e.to]  > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], (ll)(e.cap - e.flow));
          if (!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
        }
      }
    }

    if (d[t] == inf) return false;
    // if (d[t] >= 0) return false;

    // add flow
    flow += a[t];
    cost += 1LL * d[t] * a[t];
    int u = t;
    while (u != s) {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
      u = edges[p[u]].from;
    }

    return true;
  }

  int run(int s, int t, int& flow) {
    flow = 0;
    ll cost = 0;
    while (SPFA(s, t, flow, cost));
    return cost;
  }

} min_cost;
map<string, int> mep;
int tot;
int getid(const string& str) {
  if (mep.count(str)) return mep[str];
  return mep[str] = ++tot;
}

const string sh = "Shanghai";
const string xa = "Xian";
const string dl = "Dalian";
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  int s, t;
  for (int cas = 1; cas <= T; ++cas) {
    min_cost.init(4 * 20000 + 5);
    tot = 0;
    mep.clear();
    int m;
    cin >> m;
    int u, v;
    string from, to;
    for (int i = 0; i < m; ++i) {
      ll dist;
      cin >> from >> to >> dist;
      u = getid(from);
      v = getid(to);
      min_cost.add_edge(2 * u, 2 * v + 1, 1, dist);
      min_cost.add_edge(2 * v, 2 * u + 1, 1, dist);
    }
    for (int i = 1; i <= tot; ++i) {
      int cap = 1;
      if (mep[sh] == i) cap = 2;
      min_cost.add_edge(2 * i + 1, 2 * i, cap, 0);
    }
    s = 0;
    t = (tot + 1) * 2 + 5;
    min_cost.add_edge(s, mep[xa] * 2 + 1, 1, 0);
    min_cost.add_edge(s, mep[dl] * 2 + 1, 1, 0);
    min_cost.add_edge(mep[sh] * 2, t, 2, 0);

    if (!mep.count(sh) || !mep.count(xa) || !mep.count(dl)) {
      cout << -1 << endl;
      continue;
    }

    int flow = 0;
    int ans = min_cost.run(s, t, flow);
    if (flow != 2) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
