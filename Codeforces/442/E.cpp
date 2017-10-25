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
const int maxn = 200000 + 20;

vector<int> T[maxn];
int init_val[maxn];
int dfn;
int in[maxn];
int out[maxn];
struct Segtree {
  struct node {
    int l, r, sum, lazy;
  } a[maxn << 2];
  void push_down(int o) {
    if (a[o].lazy) {
      a[lson].sum = (a[lson].r - a[lson].l) - a[lson].sum;
      a[rson].sum = (a[rson].r - a[rson].l) - a[rson].sum;
      a[lson].lazy ^= 1;
      a[rson].lazy ^= 1;
      a[o].lazy = 0;
    }
  }
  void push_up(int o) {
    a[o].sum = a[lson].sum + a[rson].sum;
  }
  void build(int* val, int l, int r, int o = 1) {
    a[o] = {l, r, 0, 0};
    if (l + 1 == r) {
      a[o].sum = val[l];
      return;
    }
    int m = (l + r) / 2;
    build(val, l, m, lson);
    build(val, m, r, rson);
    push_up(o);
  }
  void update(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].sum = (a[o].r - a[o].l) - a[o].sum;
      a[o].lazy ^= 1;
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) update(l, r, lson);
    if (r > m) update(l, r, rson);
    push_up(o);
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].sum;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    int ret = 0;
    if (l < m) ret += query(l, r, lson);
    if (r > m) ret += query(l, r, rson);
    return ret;
  }
} seg;
void dfs(int x) {
  in[x] = ++dfn;
  for (int v : T[x]) {
    dfs(v);
  }
  out[x] = dfn;
}
void work() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    T[p].push_back(i);
  }
  dfn = 0;
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &init_val[in[i]]);
  }
  seg.build(init_val, 1, n + 1);
  int Q;
  scanf("%d", &Q);
  char opt[5];
  int v;
  for (int i = 0; i < Q; ++i) {
    scanf("%s%d", opt, &v);
    if (opt[0] == 'g') {
      printf("%d\n", seg.query(in[v], out[v] + 1));
    } else {
      seg.update(in[v], out[v] + 1);
    }
  }
}
int main() {
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
