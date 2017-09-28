/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int P = 1999997;

#define lson o << 1
#define rson o << 1 | 1

int N, M;
bool destory[maxn];
vector<int> G[maxn];
bool del[maxn];
int hs[P];
int& mep(int x) {
  return hs[x % P];
}
struct query {
  int c, x, y, ans;
} ;
vector<query> Qs;
int id[maxn], sz[maxn], depth[maxn], fa[maxn], top[maxn], son[maxn], tot;
void dfs(int u, int p, int d) {
  sz[u] = 1;
  depth[u] = d;
  fa[u] = p;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v != p) {
      dfs(v, u, d + 1);
      sz[u] += sz[v];
    }
    if (son[u] < 0 || sz[son[u]] < sz[v]) {
      son[u] = v;
    }
  }
}
void dfs2(int u, int first) {
  id[u] = ++tot;
  if (son[u] != -1) {
    dfs2(son[u], first);
  }
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
struct SegTree {
  struct node {
    int l, r, sum, lazy;
  } a[maxn << 2];
  void push_down(int o) {

  }
  void push_up(int o) {

  }
  void build(int l, int r, int o = 1) {
    a[o] = {l, r, 0, 0};
    if (l + 1 == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
  }
  void update(int l, int r, int val, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].lazy = val;
      a[o].sum = (a[o].r - a[o].l) * val;
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) {
      update(l, r, val, lson);
    }
    if (r > m) {
      update(l, r, val, rson);
    }
  }
} seg;
int main() {
  N = read();
  M = read();
  for (int i = 0; i < M; ++i) {
    static int x, y;
    x = read();
    y = read();
    if (x > y) swap(x, y);
    mep(x * N + y) = i;
  }
  int opt, x, y;
  for (;;) {
    opt = read();
    if (opt == -1) {
      break;
    }
    x = read();
    y = read();
    if (x > y) swap(x, y);
    Qs.push_back({opt, x, y, 0});
    if (!opt) {
      del[mep(x * N + y)] = 1;
    }
  }
}
