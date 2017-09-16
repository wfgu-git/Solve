/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define lson o << 1
#define rson o << 1 | 1
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, q;
int val[maxn];
vector<vector<int> > G;
int arc[maxn], sz[maxn], tid[maxn], top[maxn], depth[maxn], son[maxn], fa[maxn], tot;
void dfs(int u, int p, int d) {
  fa[u] = p;
  depth[u] = d;
  sz[u] = 1;
  for (int v : G[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
      sz[u] += sz[v];
      if (son[u] == -1 || sz[v] > sz[son[u]]) {
        son[u] = v;
      }
    }
  }
}
void link(int u, int first) {
  top[u] = first;
  tid[u] = ++tot;
  arc[tid[u]] = u;
  if (son[u] == -1) {
    link(son[u], first);
  }
  for (int v : G[u]) {
    if (v != son[u] && v != fa[u]) {
      link(v, v);
    }
  }
}
struct SegTree {
  struct node {
    int l, r;
    vector<int> vi;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].vi.insert(a[o].vi.end(), a[lson].vi.begin(), a[lson].vi.end());
    a[o].vi.insert(a[o].vi.end(), a[rson].vi.begin(), a[rson].vi.end());
  }
  void build(int l, int r, int o = 1) {
    a[o].l = l;
    a[o].r = r;
    a[o].vi.clear();
    if (l + 1 == r) {
      a[o].vi = {val[arc[l]]};
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  vector<int> query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].vi;
    }
    int m = (a[o].l + a[o].r) / 2;
    vector<int> ret, tmp1, tmp2;
    if (l < m) {
      tmp1 = query(l, m, lson);
    }
    if (r > m) {
      tmp2 = query(m, r, rson);
    }
    ret.insert(ret.end(), tmp1.begin(), tmp1.end());
    ret.insert(ret.end(), tmp2.begin(), tmp2.end());
    return ret;
  }
} seg;
void cut_init() {
  memset(son, -1, sizeof(son));
  tot = 0;
  dfs(1, 0, 0);
  link(1, 1);
}
int solve(int u, int v, int k) {
  bool flag = depth[u] < depth[v];
  vector<int> ret, tmp;
  while (top[u] != top[v]) {
    bool t = 0;
    if (depth[top[u]] < depth[top[v]]) {
      swap(u, v);
    }
    tmp = seg.query(tid[top[u]], tid[u] + 1);
    if (!t) reverse(tmp.begin(), tmp.end());
    ret.insert(ret.end(), tmp.begin(), tmp.end());
    u = fa[top[u]];
  }
  bool t = 0;
  if (depth[u] > depth[v]) {
    t = 1;
    swap(u, v);
  }
  tmp = seg.query(tid[top[u]], tid[u] + 1);
  if (!t) {
    reverse(tmp.begin(), tmp.end());
  }
  ret.insert(ret.end(), tmp.begin(), tmp.end());
  int ans = 0;
  if (flag) reverse(ret.begin(), ret.end());
  for (int i = 0; i < ret.size(); i += k) {
    ans ^= ret[i];
  }
  return ans;
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> q) {
    G.resize(n + 2);
    G.clear();
    for (int i = 1; i < n; ++i) {
      static int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
      cin >> val[i];
    }
    cut_init();
    seg.build(1, n + 1);
    for (int i = 0; i < q; ++i) {
      static int u, v, k;
      cin >> u >> v >> k;
      cout << solve(u, v, k) << endl;
    }
  }
  return 0;
}
