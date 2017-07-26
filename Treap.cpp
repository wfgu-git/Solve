#include <bits/stdc++.h>
using namespace std;
struct Treap {
  Treap* ch[2];
  int key, fix, size;

  Treap(int x) : key(x) {
    size = 1;
    fix = rand();
    ch[0] = ch[1] = nullptr;
  }
  int comp(int x) const {
    if (x == key) return -1;
    return x < key ? 0 : 1;
  }
  void maintain() {
    size = 1;
    if (ch[0] != nullptr) size += ch[0]->size;
    if (ch[1] != nullptr) size += ch[1]->size;
  }
};
bool fnd(Treap* o, int x) {
  while (o != nullptr) {
    int d = o->comp(x);
    if (d == -1) return true;
    o = o->ch[d];
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
void insert(Treap* &o, int x) {;
  if (o == nullptr) {
    o = new Treap(x);
  } else {
    int d = o->comp(x);
    // int d = (x < o->key ? 0 : 1);
    insert(o->ch[d], x);
    if (o->ch[d]->fix > o->fix) rotate(o, d ^ 1);
  }
  o->maintain();
}
void remove(Treap* &o, int x) {
  int d = o->comp(x);
  if (d == -1) {
    Treap* u = o;
    if (o->ch[0] != nullptr && o->ch[1] != nullptr) {
      int dd = (o->ch[0]->fix > o->ch[1]->fix ? 1 : 0);
      rotate(o, dd);
      remove(o->ch[dd], x);
    } else {
      if (o->ch[0] == nullptr) o = o->ch[1];
      else o = o->ch[0];
      delete u;
      u = nullptr;
    }
  } else {
    remove(o->ch[d], x);
  }
  if (o != nullptr) o->maintain();
}
void clear(Treap* &o) {
  if (o->ch[0] != nullptr) clear(o->ch[0]);
  if (o->ch[1] != nullptr) clear(o->ch[1]);
  delete o;
  o = nullptr;
}
int Kth(Treap* o, int k) {
  if (o == nullptr || k <= 0 || k > o->size) return -1;
  int s = o->ch[0] == nullptr ? 0 : o->ch[0]->size;
  if (s + 1 == k) return o->key;
  else if (s >= k) return Kth(o->ch[0], k);
  else return Kth(o->ch[1], k - s - 1);
}
int Rnk(Treap* o, int x) {
  int r;
  if (o == nullptr) return 0;
  if (o->ch[0] == nullptr) r = 0;
  else r = o->ch[0]->size;
  if (x == o->key) return r + 1;
  if (x < o->key) return Rnk(o->ch[0], x);
  else return r + 1 + Rnk(o->ch[1], x);
}
