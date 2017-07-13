#include <bits/stdc++.h>
using namespace std;
struct Treap {
  Treap* ch[2];
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
} *treap;
void rotate(Treap* &o, int d) {
  Treap* k = o->ch[d ^ 1];
  o->ch[d ^ 1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}
void insert(Treap* &o, int x) {
  if (o == NULL) {
    o = new Treap(x);
  } else {
    int d = o->comp(x);
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
      int d2 = (o->ch[0]->fix > o->ch[1]->fix ? 1 : 0);
      rotate(o, d);
      remove(o->ch[d], x);
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
  int s = o->ch[0] == NULL ? 0 : o->ch[0]->size;
  if (s + 1 == k) return o->key;
  else if (s >= k) return Kth(o->ch[0], k);
  else return Kth(o->ch[1], k - s - 1);
}
int Rnk(Treap* o, int x) {
  int r;
  if (o == NULL) return 0;
  if (o->ch[0] == NULL) r = 0;
  else r = o->ch[0]->size;
  if (x == o->key) return r + 1;
  if (x < o->key) return Rnk(o->ch[0], x);
  else return r + 1 + Rnk(o->ch[1], x);
}
const int maxv = 1e9;
const int maxn = 1e5;
map< int, int > info;
int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    treap = NULL;
    info.clear();
    int id, g;
    scanf("%d%d\n", &id, &g);
    printf("%d 1\n", id);
    info[g] = id;
    insert(treap, g);
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &id, &g);
      info[g] = id;
      insert(treap, g);
      int ans;
      int k = Rnk(treap, g);
      int g1 = Kth(treap, k - 1);
      int g2 = Kth(treap, k + 1);
      if (g1 == -1) ans = g2;
      else if (g2 == -1) ans = g1;
      else {
        if (g - g1 <= g2 - g) ans = g1;
        else ans = g2;
      }
      printf("%d %d\n", id, info[ans]);
    }
    clear(treap);
  }
  return 0;
}
