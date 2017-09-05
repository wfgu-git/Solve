/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

#define lson o << 1
#define rson o << 1 | 1
struct Segtree {
  struct node {
    int l, r, val, lazy;
  } a[maxn << 2];
  void push_down(int o) {
    if (a[o].lazy) {
      a[lson].val = a[rson].val = 1 << a[o].lazy;
      a[lson].lazy = a[rson].lazy = a[o].lazy;
      a[o].lazy = 0;
    }
  }
  void push_up(int o) {
    a[o].val = a[lson].val | a[rson].val;
  }
  void build(int l, int r, int o = 1) {
    a[o].l = l;
    a[o].r = r;
    a[o].val = 0;
    a[o].lazy = 0;
    if (l + 1 == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  void update(int l, int r, int c, int o = 1) {
    if (r < a[o].l || l > a[o].r) {
      return;
    }
    if (l <= a[o].l && a[o].r <= r) {
      a[o].lazy = c;
      a[o].val = 1 << c;
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) update(l, r, c, lson);
    if (r > m) update(l, r, c, rson);
    push_up(o);
  }
  int query(int l, int r, int o = 1) {
    if (r < a[o].l || l > a[o].r) {
      return 0;
    }
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].val;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    int ret = 0;
    if (l < m)  ret = query(l, r, lson);
    if (r > m)  ret |= query(l, r, rson);
    return ret;
  }
} seg;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);

  int L, T, O;
  while (scanf("%d%d%d", &L, &T, &O) != EOF) {
    seg.build(1, L + 1);
    seg.update(1, L + 1, 1);
    char op[2];
    int x, y, z;
    for (int i = 0; i < O; ++i) {
      scanf("%s", op);
      if (op[0] == 'P') {
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        printf("%d\n", __builtin_popcount(seg.query(x, y + 1)));
      } else {
        scanf("%d%d%d", &x, &y, &z);
        if (x > y) swap(x, y);
        seg.update(x, y + 1, z);
      }
    }
  }
  return 0;
}
