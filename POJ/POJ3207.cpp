#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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
  bool run() {
    // ...
    scc();
    int n = V / 2;
    // for (int i = 1; i <= n; ++i) {
    //   printf("comp[%d] = %d  comp[%d] = %d\n", i, comp[i], i + n, comp[i + n]);
    // }
    for (int i = 1; i <= n; ++i) {
      if (comp[i] == comp[i + n]) {
        return false;
      }
    }
    return true;
  }
} tsat;
int N, M;
int x[maxn], y[maxn];
void work() {
  tsat.init(M);
  for (int i = 1; i <= M; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    ++x[i]; ++y[i];
    if (x[i] > y[i]) swap(x[i], y[i]);
  }
  for (int i = 1; i <= M; ++i) {
    for (int j = i + 1; j <= M; ++j) {
      if ( (x[i] <= x[j] && y[i] <= y[j] && y[i] >= x[j])
        || (x[i] >= x[j] && y[i] >= y[j] && x[i] <= y[j])) {
        tsat.add_edge(i, j + M);
        tsat.add_edge(j, i + M);
        tsat.add_edge(i + M, j);
        tsat.add_edge(j + M, i);
      }
    }
  }
  printf("%s\n", tsat.run() == true ? "panda is telling the truth..." : "the evil panda is lying again");
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
