/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1000000+ 20;

struct edge {
  int from, to, dist;
} ;
int n, m, s;
vector<int> G[maxn];
vector<int> rG[maxn];
vector<pair<int, ll> > dag[maxn];
vector<edge> edges;
vector<int> vs;
bool vis[maxn];
int scc_tot;
int sccno[maxn];
ll val[maxn];
ll f[maxn];
ll a[maxn];
void DFS(int x) {
  vis[x] = true;
  for (int i = 0; i < G[x].size(); ++i) {
    if (!vis[G[x][i]]) DFS(G[x][i]);
  }
  vs.push_back(x);
}
void rDFS(int x, int k) {
  vis[x] = true;
  sccno[x] = k;
  for (int i = 0; i < rG[x].size(); ++i) {
    if (!vis[rG[x][i]]) rDFS(rG[x][i], k);
  }
}
ll dp(int x) {
  if (f[x] != -1) return f[x];
  ll mx = 0;
  for (pair<int, ll> & pil : dag[x]) {
    int v = pil.first;
    ll w = pil.second;
    mx = max(mx, dp(v) + w);
  }
  return f[x] = mx + val[x];
}
void work() {
  for (ll i = 1; a[i - 1] < 1e16; ++i) {
    a[i] = a[i - 1] + i * (i + 1) / 2LL;
  }
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
    rG[i].clear();
  }
  edges.clear();
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back(v);
    rG[v].push_back(u);
    edges.push_back({u, v, w});
  }
  cin >> s;

  memset(vis, 0, sizeof(vis));
  vs.clear();
  for (int v = 1; v <= n; ++v) {
    if (!vis[v]) DFS(v);
  }
  memset(vis, 0, sizeof(vis));
  int k = 0;
  for (vector<int>::reverse_iterator it = vs.rbegin(); it != vs.rend(); ++it) {
    if (!vis[*it]) rDFS(*it, k++);
  }
  scc_tot = k;

  for (const edge & e : edges) {
    int u = sccno[e.from];
    int v = sccno[e.to];
    ll w = e.dist;
    if (u == v) {
      ll t = (ll)sqrt(w * 2LL);
      if (t * (t + 1) > w * 2LL) --t;
      if ((t + 1) * (t + 2) <= w * 2LL) ++t;
      ll tmp = (t + 1) * w - a[t];
      val[u] += tmp;
      continue;
    }
    dag[u].push_back({v, w});
  }

  memset(f, -1, sizeof(f));
  dp(sccno[s]);
  cout << f[sccno[s]] << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
