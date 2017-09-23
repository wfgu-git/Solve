/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 2e9;
const int maxn = 200000 + 20;
#define lson o << 1
#define rson o << 1 | 1


struct SegTree {
  struct node {
    int l, r;
    ll pmax, nmin, amin;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].amin = min(a[lson].amin, a[rson].amin);
    a[o].pmax = max(a[lson].pmax, a[rson].pmax);
    a[o].nmin = min(a[lson].nmin, a[rson].nmin);
  }
  void build(ll* val, int l, int r, int o = 1) {
    a[o].l = l;
    a[o].r = r;
    a[o].amin = inf;
    a[o].nmin = inf;
    a[o].pmax = -inf;
    if (l + 1 == r) {
      if(val[l] < 0) {
        a[o].nmin = val[l];
      }
      else if (val[l] > 0) {
        a[o].pmax = val[l];
      }
      a[o].amin = abs(val[l]);
      return;
    }
    int m = (l + r) / 2;
    build(val, l, m, lson);
    build(val, m, r, rson);
    push_up(o);
  }
  void update(int p, ll v, int o = 1) {
    if (a[o].l == p && a[o].l + 1 == a[o].r) {
      if (v > 0) {
        a[o].pmax = v;
        a[o].nmin = inf;
      } else if (v < 0) {
        a[o].nmin = v;
        a[o].pmax = -inf;
      }
      // printf("before a[%d] -- %d\n", a[o].l, a[o].amin);
      a[o].amin = abs(v);
      // printf("after a[%d] -- %d\n", a[o].l, a[o].amin);
      return;
    }
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) update(p, v, lson);
    else  update(p, v, rson);
    push_up(o);
  }
  void query(int l, int r, ll& x, ll& y, ll& z, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      x = a[o].nmin;
      y = a[o].amin;
      z = a[o].pmax;

    // cout << a[o].l << " " << a[o].r - 1 << "  " << x << " " << y << " " << z << endl;
      return;
    }
    int m = (a[o].l + a[o].r) / 2;
    ll xx, yy, zz;
    xx = yy = inf; x = y = inf;
    zz = -inf; z = -inf;
    if (l < m) query(l, r, x, y, z, lson);
    if (r > m) query(l, r, xx, yy, zz, rson);
    x = min(x, xx);
    y = min(y, yy);
    z = max(z, zz);
    // cout << a[o].l << " " << a[o].r - 1 << "  " << x << " " << y << " " << z << endl;
  }
} seg;

ll w[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n, k, q;
    cin >> k;
    n = (1 << k);
    for (int i = 1; i <= n; ++i) {
      cin >> w[i];
    }
    seg.build(w, 1, n + 1);
    cin >> q;
    while (q--) {
      int opt, x, y;
      cin >> opt >> x >> y;
      if (opt == 1) {
        ++x, ++y;
        ll xx, yy, zz;
        xx = inf, yy = inf, zz = -inf;
        seg.query(x, y + 1, xx, yy, zz);
        // cout << xx << "  " << yy << "  " << zz << endl;
        if (xx == inf || zz == -inf) {
          cout << 1LL * yy * yy << endl;
        } else {
          cout << 1LL * xx * zz << endl;
        }
      } else if (opt == 2) {
        ++x;
        seg.update(x, y);
      }
    }
  }
}
