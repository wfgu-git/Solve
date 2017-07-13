#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct Node {
  Node* ch[2];
  int key, fix, size;

  Node(int x) : key(x) {
    size = 1;
    fix = rand();
    ch[0] = ch[1] = NULL;
  }
  int comp(int x) const {
    if (x == key) return -1;
    return x < key ? 0 : 1;
  }
  void maintain() {
    size = 1;
    if (ch[0] != NULL) size += ch[0]->size;
    if (ch[1] != NULL) size += ch[1]->size;
  }
};
void rotate(Node* &o, int d) {
  Node* k = o->ch[d ^ 1];
  o->ch[d ^ 1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}
void insert(Node* &o, int x) {
  if (o == NULL) {
    o = new Node(x);
  } else {
    // int d = o->comp(x);
    int d = x < o->key ? 0 : 1;
    insert(o->ch[d], x);
    if (o->ch[d]->fix > o->fix) rotate(o, d ^ 1);
  }
  o->maintain();
}
void remove(Node* &o, int x) {
  int d = o->comp(x);
  if (d == -1) {
    Node* u = o;
    if (o->ch[0] != NULL && o->ch[1] != NULL) {
      int dd = (o->ch[0]->fix > o->ch[1]->fix ? 1 : 0);
      rotate(o, dd);
      remove(o->ch[dd], x);
    } else {
      if (o->ch[0] == NULL) o = o->ch[1];
      else o = o->ch[0];
      delete u;
      u = NULL;
    }
  } else {
    remove(o->ch[d], x);
  }
  if (o != NULL) o->maintain();
}
void clear(Node* &o) {
  if (o->ch[0] != NULL) clear(o->ch[0]);
  if (o->ch[1] != NULL) clear(o->ch[1]);
  delete o;
  o = NULL;
}
int Kth(Node* o, int k) {
  if (o == NULL || k <= 0 || k > o->size) return 1;
  int s = o->ch[1] == NULL ? 0 : o->ch[1]->size;
  if (s + 1 == k) return o->key;
  else if (s >= k) return Kth(o->ch[1], k);
  else return Kth(o->ch[0], k - s - 1);
}
int Rnk(Node* o, int x) {
  int r;
  if (o == NULL) return 0;
  if (o->ch[0] == NULL) r = 0;
  else r = o->ch[0]->size;
  if (x == o->key) return r + 1;
  if (x < o->key) return Rnk(o->ch[0], x);
  else return r + 1 + Rnk(o->ch[1], x);
}
const int maxn =200000 + 2000;
int fa[maxn + 2], sz[maxn + 2];
void init(const int &n) {
  for (int i = 0; i <= n; i++) fa[i] = i, sz[i] = 1;
}
int fnd(int x) {
  if (fa[x] != x) fa[x] = fnd(fa[x]);
  return fa[x];
}
void mgr(int u, int v, Node* &rt) {
  u = fnd(u);
  v = fnd(v);
  if (u == v) return;
  if (sz[u] != 1) remove(rt, sz[u]);
  if (sz[v] != 1) remove(rt, sz[v]);
  insert(rt, sz[u] + sz[v]);
  fa[u] = v;
  sz[v] += sz[u];
}
int main() {
  int n, m;
  Node* treap = NULL;
  while (scanf("%d%d", &n, &m) == 2) {
  // scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; i++) {
      int op;
      scanf("%d", &op);
      if (op == 0) {
        int u, v;
        scanf("%d%d", &u, &v);
        mgr(u, v, treap);
      } else {
        int k;
        scanf("%d", &k);
        printf("%d\n", Kth(treap, k));
      }
    }
    clear(treap);
  }
  return 0;
}
