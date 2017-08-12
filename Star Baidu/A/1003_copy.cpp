#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
struct edge {
  int to, len;
  edge *next;
  edge() {}
  edge(int t, int l, edge *n) : to(t), len(l), next(n) {}
} pe[1000010], *g[500010];
struct node {
  int l, r, m;
  pii v;
  node *lch, *rch;
  node() {}
  node(int L, int R) : l(L), r(R) {
    m = (l + r) >> 1;
    lch = rch = NULL;
  }
} pn[1000010], *root;
struct que {
  int a, b, id;
  bool operator<(const que &x) const { return a < x.a; }
} qrr[500010];
const pii nil = pii(-1, -1), wild = pii(0, 0);
int n, m, q, eT, nT, U[500010], V[500010], L[500010], R[500010];
long long len[500010], ans[500010];
int fa[500010], dep[500010], son[500010], top[500010], siz[500010], W;
inline int rd() {
  int a = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) (a *= 10) += c - '0', c = getchar();
  return a;
}
void dfs1(int p) {
  siz[p] = 1;
  for (edge *t = g[p]; t; t = t->next) {
    if (t->to == fa[p]) continue;
    fa[t->to] = p;
    dep[t->to] = dep[p] + 1;
    len[t->to] = len[p] + t->len;
    dfs1(t->to);
    if (siz[t->to] > siz[son[p]]) son[p] = t->to;
  }
}
void dfs2(int p, int T) {
  top[p] = T;
  L[p] = W++;
  if (son[p]) dfs2(son[p], T);
  for (edge *t = g[p]; t; t = t->next) {
    if (t->to == fa[p] || t->to == son[p]) continue;
    dfs2(t->to, t->to);
  }
  R[p] = W;
}
int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      v = fa[top[v]];
    else
      u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
long long dist(pii v) {
  if (v == nil) return 0;
  return len[v.first] + len[v.second] - 2 * len[lca(v.first, v.second)];
}
pii merge(pii a, pii b) {
  if (a == nil || b == nil) return nil;
  if (a == wild) return b;
  if (b == wild) return a;
  int l = lca(a.first, a.second);
  int u = b.first, v = b.second, cnt = 0;
  if (L[u] >= L[l] && L[u] < R[l]) cnt++;
  if (L[v] >= L[l] && L[v] < R[l]) cnt++, swap(u, v);
  pii ret;
  if (!cnt)
    ret = nil;
  else if (cnt == 1)
    ret = pii(lca(a.first, u), lca(a.second, u));
  else {
    ret.first = lca(a.first, u);
    if (ret.first == l) ret.first = lca(a.second, u);
    ret.second = lca(a.first, v);
    if (ret.second == l) ret.second = lca(a.second, v);
  }
  if (ret.first == ret.second) ret = nil;
  return ret;
}
void build(node *p) {
  if (p->r - p->l == 1) {
    p->v = pii(U[p->l], V[p->l]);
    return;
  }
  p->lch = &(pn[nT++] = node(p->l, p->m));
  build(p->lch);
  p->rch = &(pn[nT++] = node(p->m, p->r));
  build(p->rch);
  p->v = merge(p->lch->v, p->rch->v);
}
pii query(node *p, int l, int r) {
  if (r <= p->l || p->r <= l) return wild;
  if (l <= p->l && p->r <= r) return p->v;
  return merge(query(p->lch, l, r), query(p->rch, l, r));
}
int main() {
  n = rd();
  int u, v, l;
  for (int i = 1; i < n; i++) {
    u = rd(), v = rd(), l = rd();
    g[u] = &(pe[eT++] = edge(v, l, g[u]));
    g[v] = &(pe[eT++] = edge(u, l, g[v]));
  }
  dfs1(1);
  dfs2(1, 1);
  m = rd();
  for (int i = 1; i <= m; i++) U[i] = rd(), V[i] = rd();
  q = rd();
  root = &(pn[nT++] = node(1, q + 1));
  build(root);
  for (int i = 0; i < q; i++) {
    int l = rd(), r = rd();
    printf("%I64d\n", dist(query(root, l, r + 1)));
  }
  return 0;
}
