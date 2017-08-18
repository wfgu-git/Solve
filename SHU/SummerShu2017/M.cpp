#include <bits/stdc++.h>
using namespace std;
#define lson o << 1
#define rson o << 1 | 1
const int maxn = 100000 + 20;
int nn;
int val[maxn];
struct Segtree {
  struct node {
    int l, r, v, min, max;
  } a[maxn << 2];
  void push_up(int o) {}
  void push_down(int o) {
    a[lson].max = max(a[lson].max, a[o].max + a[lson].v);
    a[lson].min = min(a[lson].min, a[o].min + a[lson].v);
    a[rson].max = max(a[rson].max, a[o].max + a[rson].v);
    a[rson].min = min(a[rson].min, a[o].min + a[rson].v);
    a[lson].v += a[o].v;
    a[rson].v += a[o].v;
    a[o].max = a[o].min = a[o].v = 0;
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].v = 0;
    a[o].min = a[o].max = 0;
    if (r - l == 1)
      return;

    int m = (l + r) >> 1;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  void update(int l, int r, int k, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].v += k;
      a[o].min = min(a[o].min, a[o].v);
      a[o].max = max(a[o].max, a[o].v);
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) >> 1;
    if (l < m) update(l, r, k, lson);
    if (r > m) update(l, r, k, rson);
    push_up(o);
  }
  int query(int p, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      return max(abs(val[p] + a[o].max), abs(val[p] + a[o].min));
    }
    push_down(o);
    int m = (a[o].l + a[o].r) >> 1;
    if (p < m) return query(p, lson);
    else return query(p, rson);
  }
} st;
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n, q;
    scanf("%d%d", &n, &q);
    nn = n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &val[i]);
    }
    st.build();
    for (int i = 0; i < q; ++i) {
      int op, l, r, k;
      scanf("%d", &op);
      if (op == 1) {
        scanf("%d%d%d", &l, &r, &k);
        st.update(l, r + 1, k);
      } else {
        scanf("%d", &k);
        printf("%d\n", st.query(k));
      }
    }
  }
  return 0;
}
