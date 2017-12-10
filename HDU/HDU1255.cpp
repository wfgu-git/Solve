/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define lson o << 1
#define rson o << 1 | 1

const int maxn = 2000 + 20;

double xset[maxn];
struct info {
  double l, r, h;
  int t;
  bool operator < (const info & rhs) const {
    return h < rhs.h;
  }
} a[maxn];
struct SegTree {
  int l, r, cover;
  double sum, ssum;
} seg[maxn << 2];
void push_up(int o) {
  if (seg[o].cover) {
    seg[o].sum = xset[seg[o].r] - xset[seg[o].l];
  } else if (seg[o].l + 1 == seg[o].r) {
    seg[o].sum = 0;
  } else {
    seg[o].sum = seg[lson].sum + seg[rson].sum;
  }

  if (seg[o].cover > 1) {
    seg[o].ssum = xset[seg[o].r] - xset[seg[o].l];
  } else if (seg[o].l + 1 == seg[o].r) {
    seg[o].ssum = 0;
  } else if (seg[o].cover == 1) {
    seg[o].ssum = seg[lson].sum + seg[rson].sum;
  }else {
    seg[o].ssum = seg[lson].ssum + seg[rson].ssum;
  }
}
void build(int l, int r, int o = 1) {
  seg[o] = {l, r, 0, 0.0, 0.0};
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
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    double x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      a[i] = {x1, x2, y1, 1};
      a[i + n] = {x1, x2, y2, -1};
      xset[i] = x1;
      xset[i + n] = x2;
    }
    n *= 2;
    sort(a, a + n);
    sort(xset, xset + n);
    int sz = unique(xset, xset + n) - xset;

    double ans = 0;
    build(0, sz);
    for (int i = 0; i < n - 1; ++i) {
      int l = lower_bound(xset, xset + sz, a[i].l) - xset;
      int r = lower_bound(xset, xset + sz, a[i].r) - xset;
      update(l, r, a[i].t);
      ans += seg[1].ssum * (a[i + 1].h - a[i].h);
    }
    printf("%.2f\n", ans);
  }
}
int main() {
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
