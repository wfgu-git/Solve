/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

struct SegTree {
  struct node {
    int l, r, max;
  } a[maxn << 2];
  void build(int l, int r, int o = 1) {
    a[o].l = l;
    a[o].r = r;
    if (l + 1 == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, o << 1);
    build(m, r, o << 1 | 1 );
  }
  void update(int p, int k, int o = 1) {
    if (a[o].l + 1 == a[o].r && a[o].l == p) {
      a[o].max = k;
      return;
    }
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) {
      update(p, k, o << 1);
    } else {
      update(p, k, o << 1 | 1);
    }
    a[o].max = max(a[o << 1].max, a[o << 1 | 1].max);
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].max;
    }
    int m = (a[o].l + a[o].r) / 2;
    int ret = -inf;
    if (l < m) {
      ret = query(l, r, o << 1);
    }
    if (r > m) {
      ret = max(ret, query(l, r, o << 1 | 1));
    }
    return ret;
  }
} seg;
int main() {
  int M, D;
  scanf("%d%d", &M, &D);
  seg.build(1, M + 1);
  char opt[2];
  int t = 0;
  int x;
  int node = 0;
  for (int i = 0; i < M; ++i) {
    scanf("%s%d", opt, &x);
    if (opt[0] == 'A') {
      seg.update(++node, (x + t) % D);
    } else {
      printf("%d\n", t = seg.query(node - x + 1, node + 1));
    }
  }
  return 0;
}
