#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 20;
struct TwoSAT {
  int n;
  vector<int> G[maxn * 2];
  bool mark[maxn * 2];
  int S[maxn * 2], c;

  bool dfs(int x) {
    if (mark[x ^ 1]) return false;
    if (mark[x]) return true;
    mark[x] = true;
    S[c++] = x;
    for (int i = 0; i < G[x].size(); ++i) {
      if (!dfs(G[x][i])) return false;
    }
    return true;
  }

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n * 2; ++i) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }

  // x = xval or y = yval
  void add_clause(int x, int xval, int y, int yval) {
    x = x * 2 + xval;
    y = y * 2 + yval;
    G[x ^ 1].push_back(y);
    G[y ^ 1].push_back(x);
  }

  bool run() {
    for (int i = 0; i < n * 2; i += 2) {
      if (!mark[i] && !mark[i + 1]) {
        c = 0;
        if (!dfs(i)) {
          while (c > 0) mark[S[--c]] = false;
          if (!dfs(i + 1)) return false;
        }
      }
    }
    return true;
  }
} ;


/*
//挑战
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000;
struct Two_Sat {
  int V, n;
  bool flag;
  vector<int> G[maxn * 2 + 20];
  vector<int> rG[maxn * 2 + 20];
  vector<int> vs;
  bool used[maxn * 2 + 20];
  int comp[maxn * 2 + 20];
  void init(int V) {
    flag = true;
    this->V = 2 * V;
    this->n = V;
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
    // for (const int& v : G[u]) {
    for (int i = 0; i < (int)G[u].size(); ++i) {
      int v = G[u][i];
      if (!used[v]) {
        dfs(v);
      }
    }
    vs.push_back(u);
  }

  void rdfs(int u, int k) {
    used[u] = true;
    comp[u] = k;
    // for (const int& v : rG[u]) {
    for (int i = 0; i < (int)rG[u].size(); ++i) {
      int v = rG[u][i];
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
    // for (int& x : vs) {
    for (int i = 0; i < (int)vs.size(); ++i) {
      int x = vs[i];
      if (!used[x]) rdfs(x, k++);
    }
    return k;
  }


  void run() {
    // ...
  }
} tsat;


*/
