/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define lson o << 1
#define rson o << 1 | 1

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

struct info {
  double l, r, h;
  int t;
  bool operator < (const info & rhs) const {
    return h < rhs.h;
  }
} a[maxn * 2];
double xset[maxn * 2];
struct Segtree {
  int l, r, val;
  double sum;
} seg[maxn * 8];
void push_up(int o) {
  if (seg[o].val) {
    seg[o].sum = xset[seg[o].r] - xset[seg[o].l]; // [l, r)
    return;
  }
  if (seg[o].l + 1 == seg[o].r) {
    seg[o].sum = 0;
    return;
  }
  seg[o].sum = seg[lson].sum + seg[rson].sum;
}
void build(int l, int r, int o = 1) {
  seg[o] = {l, r, 0, 0.0};
  if (l + 1 == r) {
    return;
  }
  int m = (l + r) / 2;
  build(l, m, lson);
  build(m, r, rson);
}
void update(int ul, int ur, int val, int o = 1) {
  if (ul <= seg[o].l && seg[o].r <= ur) {
    seg[o].val += val;
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
  int kase = 0;
  while (scanf("%d", &n) != EOF && n) {
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

    build(0, sz);
    double ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      int l = lower_bound(xset, xset + sz, a[i].l) - xset;
      int r = lower_bound(xset, xset + sz, a[i].r) - xset;
      update(l, r, a[i].t);
      ans += seg[1].sum * (a[i + 1].h - a[i].h);
    }
    printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++kase, ans);
  }
}
int main() {
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
