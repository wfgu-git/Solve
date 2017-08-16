#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int V;
vector<int> G[maxn * 2 + 20];
vector<int> rG[maxn * 2 + 20];
vector<int> vs;
bool used[maxn * 2 + 20];
int comp[maxn * 2 + 20];
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
int N, M;
void work() {
  for (int i = 1; i <= N * 2; ++i) {
    G[i].clear();
    rG[i].clear();
  }
  scanf("%d%d", &N, &M);
  V = 2 * N;
  for (int i = 0; i < M; ++i) {
    char tu, tv;
    int u, v;
    cin >> tu >> u >> tv >> v;
    // scanf("%c%d%c%d", &tu, &u, &tv, &v);
    if (tu == 'm') {
      if (tv == 'm') {
        add_edge(u + N, v);
        add_edge(v + N, u);
      } else {
        add_edge(u + N, v + N);
        add_edge(v, u);
      }
    } else if (tu == 'h') {
      if (tv == 'm') {
        add_edge(u, v);
        add_edge(v + N, u + N);
      } else {
        add_edge(u, v + N);
        add_edge(v, u + N);
      }
    }
  }
  scc();
  for (int i = 1; i <= N; ++i) {
    if (comp[i] == comp[N + i]) {
      printf("BAD\n");
      return;
    }
  }
  printf("GOOD\n");
}
int main() {
  // freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
}
