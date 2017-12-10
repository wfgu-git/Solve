/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000 + 20;

#define lson o << 1
#define rson o << 1 | 1
struct info {
  int l, r, h, t;
  bool operator < (const info & rhs) const {
    return h < rhs.h;
  }
} a[maxn];
struct SegTree {
  int l, r;
  int lp, rp;
  int cover, length;
  int num;
} seg[maxn << 2];
int xset[maxn];
void push_up(int o) {
  if (seg[o].cover) {
    seg[o].length = xset[seg[o].r] - xset[seg[o].l];
    seg[o].lp = seg[o].rp = seg[o].num = 1;
  } else if (seg[o].l + 1 == seg[o].r) {
    seg[o].lp = seg[o].rp = 0;
    seg[o].length = seg[o].num = 0;
  } else {
    seg[o].length = seg[lson].length + seg[rson].length;
    seg[o].lp = seg[lson].lp;
    seg[o].rp = seg[rson].rp;
    seg[o].num = seg[lson].num + seg[rson].num - (seg[lson].rp && seg[rson].lp);
  }
}
void build(int l, int r, int o = 1) {
  seg[o] = {l, r, 0, 0, 0, 0, 0};
  if (l + 1 == r) {
    return;
  }
  int m = (l + r) / 2;
  build(l, m, lson);
  build(m, r, rson);
}
void update(int ul, int ur, int val, int o = 1) {
  if (ul <= seg[o].l && seg[o].r <= ur) {
    seg[o].cover += val;
    push_up(o);
    return;
  }
  int m = (seg[o].l + seg[o].r) / 2;
  if (ul < m) update(ul, ur, val, lson);
  if (ur > m) update(ul, ur, val, rson);
  push_up(o);
}
void work() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      a[i] = {x1, x2, y1, 1};
      a[i + n] = {x1, x2, y2, -1};
      xset[i] = x1;
      xset[i + n] = x2;
    }
    n *= 2;
    sort(a, a + n);
    sort(xset, xset + n);
    int sz = unique(xset, xset + n) - xset;

    int ans = 0, last = 0;
    build(0, sz);
    for (int i = 0; i < n; ++i) {
      int l = lower_bound(xset, xset + sz, a[i].l) - xset;
      int r = lower_bound(xset, xset + sz, a[i].r) - xset;
      update(l, r, a[i].t);
      if (i < n - 1) {
        ans += seg[1].num * 2 * (a[i + 1].h - a[i].h);
      }
      ans += abs(seg[1].length - last);
      last = seg[1].length;
    }
    printf("%d\n", ans);
  }
}
int main() {
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
