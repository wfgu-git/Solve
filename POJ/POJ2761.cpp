#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
void debug() {cout << "!!!!!!!!!!" << endl;}
struct Treap {
  Treap *ch[2];
  int key, fix, size;

  Treap(int x) : key(x) {
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
bool fnd(Treap* o, int x) {
  while (o != NULL) {
    int d = o->comp(x);
    if (d == -1) return true;
    else o = o->ch[d];
  }
  return false;
}
void rotate(Treap* &o, int d) {
  Treap* k = o->ch[d ^ 1];
  o->ch[d ^ 1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}
void insert(Treap* &o, int x) {
  // if (fnd(o, x)) return;
  if (o == NULL) {
    o = new Treap(x);
  } else {
    // int d = o->comp(x);
    int d = (x < o->key ? 0 : 1);
    insert(o->ch[d], x);
    if (o->ch[d]->fix > o->fix) rotate(o, d ^ 1);
  }
  o->maintain();
}
void remove(Treap* &o, int x) {
  int d = o->comp(x);
  if (d == -1) {
    Treap* u = o;
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
void clear(Treap* &o) {
  if (o->ch[0] != NULL) clear(o->ch[0]);
  if (o->ch[1] != NULL) clear(o->ch[1]);
  delete o;
  o = NULL;
}
int Kth(Treap* o, int k) {
  if (o == NULL || k <= 0 || k > o->size) return -1;
  int sz = (o->ch[0] == NULL ? 0 : o->ch[0]->size);
  if (sz + 1 == k) return o->key;
  else if (sz >= k) return Kth(o->ch[0], k);
  else return Kth(o->ch[1], k - sz - 1);
}
const int maxn = 100001 + 10;
const int maxq = 50001 + 10;
int a[maxn + 1];
struct query {
  int l, r, k, id;
  bool operator < (const query &rhs) const {
    return l < rhs.l;
  }
} qry[maxq + 1];
int ans[maxq + 1];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    Treap* tree = NULL;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &qry[i].l, &qry[i].r, &qry[i].k);
      qry[i].id = i;
    }
    sort(qry, qry + m);
    int l = qry[0].l;
    int r = qry[0].l;
    for (int i = 0; i < m; i++) {
      int now = qry[i].id;
      int k = qry[i].k;
      int ql = qry[i].l;
      int qr = qry[i].r;
      while (l < ql) remove(tree, a[l++]);
      while (r <= qr) insert(tree, a[r++]);
      ans[now] = Kth(tree, k);
    }
    for (int i = 0; i < m; i++) {
      printf("%d\n", ans[i]);
    }
    clear(tree);
  }
  return 0;
}
