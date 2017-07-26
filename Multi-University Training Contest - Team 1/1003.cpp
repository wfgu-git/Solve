#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 20;
int nn, cont, head[maxn];
struct Edge {int u, v, next;} edge[maxn * 2];
void add_edge(int u, int v) {
  edge[cont] = {u, v, head[u]};
  edge[cont + nn] = {v, u, head[v]};
  head[u] = cont;
  head[v] = cont + nn;
  cont++;
}
int ans;
map<int, int> *root[maxn];
void dfs(int u, int p) {
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == p) continue;
    dfs(v, u);
    if (root[u]->size() < root[v]->size()) swap(root[u], root[v]);

  }
}
void init(int n) {
  nn = n;
  ans = 0;
  cont = 1;
  memset(head, -1, sizeof(head));
}
int w[maxn];
int main() {
  int n;
  int kase = 0;
  while (scanf("%d", &n) != EOF) {
    init(n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", w + i);
    }
    for (int i = 1; i < n; i++) {
      static int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
    }
    dfs(1, 0);
    printf("Case #%d: %d\n", ++kase, ans);
  }
  return 0;
}
