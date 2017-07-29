#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 50000 + 20;
int nn, cont, head[maxn];
struct Edge {int u, v, d, next;} edge[maxn * 2];
void add_edge(int u, int v, int d) {
  edge[cont] = {u, v, d, head[u]};
  edge[cont + nn] = {v, u, d, head[v]};
  head[u] = cont;
  head[v] = cont + nn;
  cont++;
}
int sz[maxn];
map<int, int> cnt;
set<int> *root[maxn];
void merge(set<int>* &a, set<int>* &b) {

}
void dfs(int u, int p) {
  sz[u] = 1;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == p) continue;
    int w = edge[i].d;
    dfs(v, u);
    sz[u] += sz[v];
    if (root[u]->size() < root[v]->size()) swap(u, v);
    merge(root[u], root[v]);
  }
  // for current node
  // do someting...

}
void solve() {
  cnt.clear();
  for (int i = 1; i <= nn; ++i) root[i] = nullptr;
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    int fac;
    scanf("%d", &fac);
    cnt[fac] = int();
  }
  for (int i = 1; i < nn; ++i) {
    int u, v;
    ll d;
    scanf("%d%d%lld", &u, &v, &d);
    add_edge(u, v, d);
  }
}
int n;
void init() {
  nn = n;
  cont = 1;
  memset(head, -1, sizeof(head));
}
int main() {
  while (scanf("%d", &n) != EOF) {
    solve();
  }
  return 0;
}
