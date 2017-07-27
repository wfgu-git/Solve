#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 20;
using ll = long long;
int n;
int nn, cont, head[maxn];
struct Edge {int u, v, next;} edge[maxn * 2];
void add_edge(int u, int v) {
  edge[cont] = {u, v, head[u]};
  edge[cont + nn] = {v, u, head[v]};
  head[u] = cont;
  head[v] = cont + nn;
  cont++;
}
int sz[maxn], fa[maxn], L[maxn], R[maxn], dfs_clock;
vector<int> col[maxn];
set<int> kind;
void dfs(int u, int p) {
  L[u] = ++dfs_clock;
  sz[u] = 1;
  fa[u] = p;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
  R[u] = dfs_clock;
}
bool comp(const int &x, const int &y) {
  return L[x] < L[y];
}
void solve(int kase) {
  ll ans = kind.size() * 1LL * n * (n - 1) / 2;

  for (const int &c : kind) {
    col[c].push_back(0);
    sort(col[c].begin(), col[c].end(), comp);
    for (const int &x : col[c]) {
      for (int i = head[x]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa[x]) continue;
        int size = sz[v];
        int k = L[v];
        while (true) {
          L[n + 1] = k;
          auto it = lower_bound(col[c].begin(), col[c].end(), n + 1, comp);
          if (it == col[c].end() || L[*it] > R[v]) break;
          size -= sz[*it];
          k = R[*it] + 1;
        }
        ans -= 1LL * size * (size - 1) / 2;
      }
    }
  }
  printf("Case #%d: %lld\n", kase, ans);
}
void init() {
  dfs_clock = 0;
  nn = n;
  cont = 1;
  kind.clear();
  memset(head, -1, sizeof(head));
  for (int i = 1; i < maxn; i++) col[i].clear();
}
int main() {
  int kase = 0;
  while (scanf("%d", &n) != EOF) {
    init();
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      col[x].push_back(i);
      kind.insert(x);
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
    }
    add_edge(0, 1);
    dfs(0, 0);
    solve(++kase);
  }
  return 0;
}
