#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000;
struct Two_Sat {
  int V;
  bool flag;
  vector<int> G[maxn * 2 + 20];
  vector<int> rG[maxn * 2 + 20];
  vector<int> vs;
  bool used[maxn * 2 + 20];
  int comp[maxn * 2 + 20];
  void init(int V) {
    flag = true;
    this->V = 2 * V;
    for (int i = 1; i <= this->V; ++i) {
      G[i].clear();
      rG[i].clear();
    }
    memset(comp, 0, sizeof(comp));
  }

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
  void run() {
    // ...
  }
} sat;
