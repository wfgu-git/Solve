/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

#define lson o << 1
#define rson o << 1 | 1

int n, q;
int raw[maxn];
struct SegTree {
  struct node {
    int l, r, val, idx;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].val = a[lson].val + a[rson].val;
  }
  void build(int* idx, int l, int r, int o = 1) {
    a[o] = {l, r, 0};
    if (l + 1 == r) {
      a[o].idx = idx[l];
      a[o].val = raw[idx[l]];
      return;
    }
    int m = (l + r) / 2;
    build(idx, l, m, lson);
    build(idx, m, r, rson);
    push_up(o);
  }
  void update(int p, int val, int o = 1) {
    if (a[o].l == p && a[o].l + 1 == a[o].r) {
      a[o].idx = val;
      a[o].val = raw[a[o].idx];
      return;
    }
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) {
      update(p, val, lson);
    }
    if (p > m) {
      update(p, val, rson);
    }
    push_up(o);
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].val;
    }
    int m = (a[o].l + a[o].r) / 2;
    int ret = 0;
    if (l < m) {
      ret += query(l, r, lson);
    }
    if (r > m) {
      ret += query(l, r, rson);
    }
    return ret;
  }
} seg;
void change(int x, int y) {
  swap(raw[x], raw[y]);
  seg.update(x, raw[x]);
  seg.update(y, raw[y]);
}
int query(int x, int y) {
  return seg.query(x, y + 1);
}
int main() {
  int T;
  T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; ++i) {
      raw[i] = read();
    }
    seg.build(raw, 1, n + 1);
    q = read();
    int opt, x, y;
    for (int i = 0; i < q; ++i) {
      opt = read(); x = read(); y = read();
      if (opt == 1) {
        change(x, y);
      } else if (opt == 2) {
        printf("%d\n", query(x, y));
      }
    }
  }
}
