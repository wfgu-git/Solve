/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

#define lson o << 1
#define rson o << 1 | 1

string s, t;

struct SegTree {
  struct node {
    int l, r, v;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].v = a[lson].v + a[rson].v;
  }
  void build(int* val, int l, int r, int o = 1) {
    a[o].l = l;
    a[o].r = r;
    a[o].v = 0;
    if (l + 1 == r) {
      a[o].v = val[l];
      return;
    }
    int m = (l + r) / 2;
    build(val, l, m, lson);
    build(val, m, r, rson);
    push_up(o);
  }
  void update(int p, int x, int o = 1) {
    if (a[o].l == p && a[o].l + 1 == a[o].r) {
      a[o].v += x;
      return;
    }
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) {
      update(p, x, lson);
    } else {
      update(p, x, rson);
    }
    push_up(o);
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].v;
    }
    int m = (a[o].l + a[o].r) / 2;
    int ret = 0;
    if (l < m) {
      ret = query(l, r, lson);
    }
    if (r > m) {
      ret += query(l, r, rson);
    }
    return ret;
  }

} seg;
int ok[maxn];
int sn, tn;
void init(const string& s, const string& t) {
  memset(ok, 0, sizeof(ok));
  sn = s.size();
  tn = t.size();
  int i, j, k;
  for (i = tn; i <= sn; ++i) {
    for (j = i - tn, k = 0; j < i; ++j, ++k) {
      if (s[j] != t[k]) {
        break;
      }
    }
    if (j == i) {
      ok[i] = 1;
    }
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int Q;
    cin >> Q;
    cin >> s >> t;
    init(s, t);
    seg.build(ok, 1, sn + 1);
    string op;
    int x, y;
    int ret;
    for (int q = 0; q < Q; ++q) {
      cin >> op;
      if (op[0] == 'Q') {
        cin >> x >> y;
        if (x + tn - 1 > y) {
          ret = 0;
        } else {
          ret = seg.query(x + tn - 1, y + 1);
        }
        cout << ret << endl;
      } else {
        cin >> x >> op;
        s[x - 1] = op[0];
        int i, j, k;
        for (i = max(x - tn, 0); i < min(sn - tn + 1, x); ++i) {
          for (j = i, k = 0; j < i + tn; ++j, ++k) {
            if (s[j] != t[k]) {
              break;
            }
          }
          if (j < i + tn) {
            if (ok[i + tn] == 1) {
              ok[i + tn] = 0;
              seg.update(i + tn, -1);
            }
          } else {
            if (ok[i + tn] == 0) {
              ok[i + tn] = 1;
              seg.update(i + tn, 1);
            }
          }
        }
      }
    }
    cout << endl;
  }
  return 0;
}
