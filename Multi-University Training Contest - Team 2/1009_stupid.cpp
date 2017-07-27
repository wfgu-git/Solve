#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1000000 + 20;
int n, m, d;
struct Treap {
  Treap* ch[2];
  long long key;
  int fix, size;

  Treap(long long x) : key(x) {
    size = 1;
    fix = rand();
    ch[0] = ch[1] = NULL;
  }
  int comp(long long x) const {
    if (x == key) return -1;
    return x < key ? 0 : 1;
  }
  void maintain() {
    size = 1;
    if (ch[0] != NULL) size += ch[0]->size;
    if (ch[1] != NULL) size += ch[1]->size;
  }
};
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
  if (o == NULL) return;
  if (o->ch[0] != NULL) clear(o->ch[0]);
  if (o->ch[1] != NULL) clear(o->ch[1]);
  delete o;
  o = NULL;
}
int Kth(Treap* o, int k) {
  if (o == NULL || k <= 0 || k > o->size) return -1;
  int sz = o->ch[0] == NULL ? 0 : o->ch[0]->size;
  if (sz + 1 == k) return o->key;
  else if (sz >= k) return Kth(o->ch[0], k);
  else return Kth(o->ch[1], k - sz - 1);
}
struct BIT {
  int n;
  int a[maxn];
  void init(int nn) {
    n = nn;
    memset(a, 0, sizeof(a));
  }
  inline int lowbit(int x) {return x & (-x);}
  void update(int x, int k) {
    while (x <= n) {
      a[x] += k;
      x += lowbit(x);
    }
  }
  int query(int x) {
    int res = 0;
    while (x) {
      res += a[x];
      x -= lowbit(x);
    }
    return res;
  }
} bit;
int main() {
  Treap* treap = NULL;
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n * m - 1; i++) {
      insert(treap, i);
    }
    bit.init(n * m - 1);
    int cur = 1;
    int del = 0;
    ll ans = 0;
    while (cur <= n * m - 1) {
      if (treap == NULL) break;
      int k = Kth(treap, cur);
      ans += bit.query(n * m - 1) - bit.query(k);
      bit.update(k, 1);
      remove(treap, k); ++del;
      cur += (d - 1);
      if (cur > n * m - 1 - del) cur = 1;
    }
    printf("%s\n", ans % 2 == 0 ? "YES" : "NO");
    clear(treap);
  }
  return 0;
}
