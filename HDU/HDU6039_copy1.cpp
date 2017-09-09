#include <bits/stdc++.h>
#define N 101000
using namespace std;

int n, m, q, cnt, l[N], r[N], ll[N], rr[N], rt[N];
typedef pair<int, int> P;
typedef pair<P, int> PP;
vector<int> g[N];
vector<PP> gg[N];
int d[N], rad[N];
bool v[N];

struct ST {
  struct node {
    int max, lazy;
    int l, r;
  } tree[N << 2];

  inline void push_up(int i) {
    tree[i].max = max(tree[i << 1].max, tree[i << 1 | 1].max);
  }

  inline void build(int i, int l, int r) {
    tree[i].r = r;
    tree[i].l = l;
    tree[i].lazy = 0;
    if (l == r) {
      tree[i].max = d[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    push_up(i);
  }

  inline void push_down(int i) {
    tree[i << 1].lazy += tree[i].lazy;
    tree[i << 1 | 1].lazy += tree[i].lazy;
    tree[i << 1].max += tree[i].lazy;
    tree[i << 1 | 1].max += tree[i].lazy;
    tree[i].lazy = 0;
  }

  inline void update(int i, int l, int r, int x) {
    if ((tree[i].l == l) && (tree[i].r == r)) {
      tree[i].lazy += x;
      tree[i].max += x;
      return;
    }
    if (tree[i].lazy != 0) push_down(i);
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (mid >= r)
      update(i << 1, l, r, x);
    else if (mid < l)
      update(i << 1 | 1, l, r, x);
    else {
      update(i << 1, l, mid, x);
      update(i << 1 | 1, mid + 1, r, x);
    }
    push_up(i);
  }

  inline int getmax(int i, int l, int r) {
    if ((tree[i].l == l) && (tree[i].r == r)) return tree[i].max;
    if (tree[i].lazy != 0) push_down(i);
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (mid >= r)
      return getmax(i << 1, l, r);
    else if (mid < l)
      return getmax(i << 1 | 1, l, r);
    else
      return max(getmax(i << 1, l, mid), getmax(i << 1 | 1, mid + 1, r));
  }

} seg;

int f[N];

int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }

void dfs(int root, int fa, int x, int dist) {
  rt[x] = root;
  l[x] = ++cnt;  // l表示某一个角速度相同的集合以及它所有后代的dfs序的左端点
  d[cnt] = dist;
  for (int i = 0; i < gg[x].size(); i++) {
    int w = gg[x][i].second;
    int y = gg[x][i].first.first;
    int u = gg[x][i].first.second;
    if (y != fa) {
      ll[u] = min(ll[u], cnt + 1);  // ll表示某一个节点的子树dfs序的左端点
      dfs(root, x, y, dist + w);
      rr[u] = max(rr[u], cnt);  // rr表示某一个节点的子树dfs序的右断点
    } else
      v[u] = 1;  // v表示该点是否与父亲共线
  }
  r[x] = cnt;  // r表示某一个角速度相同的集合以及它所有后代的dfs序的左端点
}

int main() {
  int T_T = 0;
  while (~scanf("%d%d%d", &n, &m, &q)) {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      ll[i] = 0x7fffffff;
      scanf("%d", &rad[i]);
      rad[i] = log2(rad[i]);
      rt[i] = rr[i] = v[i] = 0;
      f[i] = i;
      g[i].clear();
      gg[i].clear();
    }
    while (m--) {
      int ty, u, v;
      scanf("%d%d%d", &ty, &u, &v);
      if (ty == 1) {
        g[u].push_back(v);
        g[v].push_back(u);
      } else
        f[find(u)] = find(v);  //共轴则合并
    }
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < g[i].size(); j++) {
        int y = g[i][j];
        gg[find(i)].push_back(
            PP(P(find(y), i), rad[i] - rad[y]));  //以集合来构建新的树
      }
    for (int i = 1; i <= n; i++)
      if (i == find(i) && !rt[i])
        dfs(i, 0, i, 0);  //标dfs序，可能是多棵树，但不影响线段树本身
    seg.build(1, 1, cnt);
    printf("Case #%d:\n", ++T_T);
    while (q--) {
      int op, x, y;
      scanf("%d%d%d", &op, &x, &y);
      y = log2(y);
      if (op == 1) {
        int delta = y - rad[x];
        int f = find(x);
        if (v[x])
          seg.update(1, l[f], r[f],
                     -delta);  //如果与父亲共线，先改变整个集合及其后代
        if (ll[x] <= rr[x])
          seg.update(
              1, ll[x], rr[x],
              delta);  //如果不共线，只需改变节点子树；共线则子树不用改变，加回去抵消刚刚减少的
        rad[x] = y;
      } else {
        x = find(x);
        int ans = y - seg.getmax(1, l[x], l[x]) +
                  seg.getmax(1, l[rt[x]], r[rt[x]]);  //结算结果
        printf("%.3f\n", ans * log(2.));              //记得乘ln2
      }
    }
  }
  return 0;
}
