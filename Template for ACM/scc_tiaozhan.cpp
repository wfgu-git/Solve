// O(V+E)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
int V;
vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;
bool used[maxn];
int comp[maxn];
void add_edge(int u, int v) {
  G[u].push_back(v);
  rG[v].push_back(u);
}
void dfs(int u) {
  used[u] = true;
  for (const int& v : G[u]) {
    if (!used[v]) {
      dfs(v);
    }
  }
  vs.push_back(u);
}
void rdfs(int u, int k) {
  used[u] = true;
  comp[u] = k;
  for (const int& v : rG[u]) {
    if (!used[v]) {
      rdfs(v, k);
    }
  }
}
int scc() {
  memset(used, 0, sizeof(used));
  vs.clear();
  for (int v = 1; v <= V; ++v) {
    if (!used[v]) dfs(v);
  }
  memset(used, 0, sizeof(used));
  int k = 0;
  reverse(vs.begin(), vs.end());
  for (int& x : vs) {
    if (!used[x]) rdfs(x, k++);
  }
  return k;
}
