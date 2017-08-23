/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> nG[maxn];
pair<int, int> edges[6000 + 20];
int deg[maxn];
vector<int> dfn;
int N, M;
bool vis[maxn];
int sccno[maxn], sccno_tot;
void add_edge(int from, int to) {
  G[from].push_back(to);
  rG[to].push_back(from);
}
void dfs(int u) {
  vis[u] = true;
  for (const int& v : G[u]) {
    if (!vis[v]) dfs(v);
  }
  dfn.push_back(u);
}
void rdfs(int u, int k) {
  vis[u] = true;
  sccno[u] = k;
  for (const int& v : rG[u]) {
    if (!vis[v]) rdfs(v, k);
  }
}
int scc() {
  memset(vis, 0, sizeof(vis));
  dfn.clear();
  for (int u = 0; u < N; ++u) {
    if (!vis[u]) dfs(u);
  }
  memset(vis, 0, sizeof(vis));
  int k = 0;
  // reverse(dfn.begin(), dfn.end());
  // for (const int& x: dfn) {
  for (auto it = dfn.rbegin(); it != dfn.rend(); ++it) {
    int x = *it;
    if (!vis[x]) rdfs(x, k++);
  }
  return k; // num of scc + 1
}
void Suodian() {
  sccno_tot = scc();
  memset(deg, 0, sizeof(deg));
  map<pair<int, int>, bool> S;
  for (int i = 0; i < M; ++i) {
    int u = sccno[edges[i].first];
    int v = sccno[edges[i].second];
    if (u != v) {
      if (S.count({u, v})) continue;
      S[{u, v}] = 1;
      nG[u].push_back(v);
      deg[v]++;
    }
  }
}
void init() {
  for (int i = 0; i < N; ++i) {
    G[i].clear();
    rG[i].clear();
    nG[i].clear();
  }
}
void work() {
  scanf("%d%d", &N, &M);
  init();
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    edges[i] = {u, v};
    add_edge(u, v);
  }
}
