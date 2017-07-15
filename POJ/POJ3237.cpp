#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000;
vector< vector< int > > g;
int sz[maxn + 2], depth[maxn + 2], fa[maxn + 2], son[maxn + 2], top[maxn + 2], id[maxn + 2];
int seg[maxn << 2 + 2];
void get_info(int u, int p, int d) {
  sz[u] = 1;
  depth[u] = d;
  fa[u] = p;
  for (auto v : g[u]) {
    if (v == p) continue;
    get_info(v, u, d + 1);
    sz[u] += sz[v];
    if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
  }
}
void dfs(int u, int first) {
  top[u] = first;
  id[u] = tot++;
  if (son[u] != -1) dfs(son[u], first);
  for (auto v : g[u]) {
    if (v != son[u])
      dfs(v, v);
  }
}
void init(int n) {
  g.resize(n + 2);
  g.clear();
  fill(son, son + n + 1, -1);
}
