#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 20;
int n, k, ans;
struct Treap {
  Treap *son[2];
  int size, cnt, key, fix;

  inline int comp(int x) const {
    if (x == key) return -1;
    return x < key ? 0 : 1;
  }
  inline void maintain() {
    size = cnt + son[0]->size + son[1]->size;
  }
} ;
Treap* null = new Treap();
Treap* root[maxn];
void rotate(Treap* &o, int d) {
  Treap* k = o->son[d ^ 1];
  o->son[d ^ 1] = k->son[d];
  k->son[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}
void insert(Treap* &o, int x, int num) {
  if (o == null) {
    o = new Treap();
    o->size = o->cnt = num;
    o->key = x;
    o->fix = rand();
    o->son[0] = o->son[1] = null;
  } else {
    o->size += num;
    int d = o->comp(x);
    if (d == -1) {
      o->cnt += num;
    } else {
      insert(o->son[d], x, num);
      if (o->son[d]->fix > o->fix) rotate(o, d ^ 1);
    }
  }
}
int rnk(Treap* o, int x) {
  if (o == null) return 0;
  int d = o->comp(x);
  if (d == -1) return o->son[0]->size + o->cnt;
  else if (d) return o->son[0]->size + o->cnt + rnk(o->son[1], x);
  return rnk(o->son[0], x);
}
void merge(Treap* &a, Treap *b) {
  if (b == null) return;
  insert(a, b->key, b->cnt);
  merge(a, b->son[0]); merge(a, b->son[1]);
}
int cnt(Treap* a, Treap* b, int x) {
  if (b == 0) return 0;
  return b->cnt * rnk(a, x - b->key) + cnt(a, b->son[0], x) + cnt(a, b->son[1], x);
}
int nn, cont, head[maxn];
struct Edge {int u, v, d, next;} edge[maxn * 2];
void add_edge(int u, int v, int d) {
  edge[cont] = {u, v, d, head[u]};
  edge[cont + nn] = {v, u, d, head[v]};
  head[u] = cont;
  head[v] = cont + nn;
  cont++;
}
void dfs(int u, int p, int d) {
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    int w = edge[i].d;
    if (v == p) continue;
    dfs(v, u, d + w);
    if (root[u]->size < root[v]->size) swap(root[u], root[v]);
    ans += cnt(root[u], root[v], k + 2 * d);
    merge(root[u], root[v]);
  }
  ans += rnk(root[u], d + k);
  insert(root[u], d, 1);
}
void init(int n) {
  nn = n;
  ans = 0;
  cont = 1;
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= n; i++) root[i] = null;
}
int main() {
  while (scanf("%d%d", &n, &k) && (n + k)) {
    init(n);
    for (int i = 1; i < n; i++) {
      int u, v, d;
      scanf("%d%d%d", &u, &v, &d);
      add_edge(u, v, d);
    }
    dfs(1, 0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
