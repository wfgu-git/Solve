#include <bits/stdc++.h>
using namespace std;
struct Treap {
  Treap* ch[2];
  int key, fix;
  int size;

  Treap(int x) {
    size = 1;
    fix = rand();
    key = x;
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
bool fnd(Treap *o, int x) {
  while (o != NULL) {
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
    Treap* tmp = o;
    if (o->ch[0] == NULL) {
      o = o->ch[1];
      delete tmp;
      tmp = NULL;
    } else if (o->ch[1] == NULL) {
      o = o->ch[0];
      delete tmp;
      tmp = NULL;
    } else {
      int dd = o->ch[0]->fix > o->ch[1]->fix ? 1 : 0;
      rotate(o, dd);
      remove(o->ch[dd], x);
    }
  } else {
    remove(o->ch[d], x);
  }
  if (o != NULL) o->maintain();
}
int Kth(Treap* o, int k) {
  if (o == NULL || k <= 0 || k > o->size) return -1;

}
void remvall(Treap* &o) {
  if (o == NULL) return;
  if (o->ch[0] != NULL) remvall(o->ch[0]);
  if (o->ch[1] != NULL) remvall(o->ch[1]);
  delete o;
  o = NULL;
}
int main() {

  return 0;
}
