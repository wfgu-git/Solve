struct Segtree {
  struct node {
    int l, r;
    int sum, min, max;
    int lazy;
  } a[maxn << 2];
  void push_up(int o) {
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].v = 0;
    //
    if (r - l == 1) return;
    int m = l + (r - l) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  void update(int p, int k, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      //
      return;
    }
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (p < m) update(p, k, lson);
    else update(p, k, rson);
    push_up(o);
  }
  void update(int l, int r, int k, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      //
      return;
    }
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      //
      return ;
    }
    //
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (l < m) ret += query(l, r, lson);
    if (r > m) ret += query(l, r, rson);
    return ret;
  }
} st;
