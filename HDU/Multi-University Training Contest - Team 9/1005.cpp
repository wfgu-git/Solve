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
vector<int> tmp[maxn];
pair<int, int> edges[6000 + 20];
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
  // reverse(dfn.begin(), dfn.end());            break;

  // for (const int& x: dfn) {
  for (auto it = dfn.rbegin(); it != dfn.rend(); ++it) {
    int x = *it;
    if (!vis[x]) rdfs(x, k++);
  }
  return k;
}
int deg[maxn];
void work() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    G[i].clear();
    rG[i].clear();
    tmp[i].clear();
  }
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    edges[i] = {u, v};
    add_edge(u, v);
  }
  sccno_tot = scc();
  memset(deg, 0, sizeof(deg));
  map<pair<int, int>, bool> used;
  for (int i = 0; i < M; ++i) {
    int u = sccno[edges[i].first];
    int v = sccno[edges[i].second];
    if (u != v) {
      if (used.count({u, v})) continue;
      used[{u, v}] = 1;
      tmp[u].push_back(v);
      deg[v]++;
    }
  }


  queue<int> Q;
  for (int i = 0; i < sccno_tot; ++i) {
    if (!deg[i]) {
      Q.push(i);
    }
  }
  if (Q.size() > 1) {
    puts("Light my fire!");
    return;
  }
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    int tot = 0;
    for (const int& v : tmp[u]) {
      if (!--deg[v]) {
        ++tot;
        Q.push(v);
      }
    }
    if (tot >= 2) {
      puts("Light my fire!");
      return;
    }
  }
  puts("I love you my love and our love save us!");
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/solve/data.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
}
