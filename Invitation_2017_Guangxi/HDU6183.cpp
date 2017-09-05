/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 30000000;
struct node {
  int l, r, v;
  int lson, rson;
} pool[maxn];
int tid;
int seg[55];
void update(int& o, int p, int x, int l, int r) {
  if (o == 0) {
    o = ++tid;
    pool[o].l = l;
    pool[o].r = r;
    pool[o].v = x;
    pool[o].lson = pool[o].rson = 0;
  }
  pool[o].v = min(pool[o].v, x);
  if (l == r) {
    return;
  }
  int m = (l + r) / 2;
  if (p <= m) update(pool[o].lson, p, x, l, m);
  else update(pool[o].rson, p, x, m + 1, r);
}
bool ok;
void query(int ql, int qr, int o, int v, int l, int r) {
  if (o == 0 || ok) {
    return;
  }
  if (ql <= l && r <= qr) {
    if (pool[o].v <= v) {
      ok = true;
    }
    return;
  }
  int m = (l + r) / 2;
  if (ql <= m) query(ql, qr, pool[o].lson, v, l, m);
  if (qr > m) query(ql, qr, pool[o].rson, v, m + 1, r);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int opt, ans;
  for (;~scanf("%d", &opt) && opt != 3;) {
    int x, y, c, y1, y2;
    if (opt == 0) {
      tid = 0;
      memset(seg, 0, sizeof(seg));
    } else if (opt == 1) {
      scanf("%d%d%d", &x, &y, &c);
      update(seg[c], y, x, 1, 1000000 + 1);
    } else if (opt == 2) {
      scanf("%d%d%d", &x, &y1, &y2);
      if (y1 > y2) swap(y1, y2);
      ans = 0;
      for (int i = 0; i <= 50; ++i) {
        ok = 0;
        query(y1, y2, seg[i], x, 1, 1000000 + 1);
        ans += ok;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
