/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 20;
const int mxlg = 20 + 5;

vector<int> raw_tree[maxn];
vector<int> virtual_tree[maxn];
vector<int> key_nodes;
int n, m;
int rem[maxn];
int vis[maxn];
int used[maxn];
int key_node[maxn];
int belong[maxn];
int depth[maxn];
int fa[mxlg][maxn];
int sz[maxn];
int dfn[maxn];
int ans[maxn];
int dfs_clock;
int S[maxn];
int comp(int x, int y) { return dfn[x] < dfn[y]; }
void dfs(int x, int p, int d) {
  dfn[x] = ++dfs_clock;
  fa[0][x] = p;
  depth[x] = d;
  sz[x] = 1;
  for (int i = 0; i < raw_tree[x].size(); ++i) {
    int v = raw_tree[x][i];
    if (v != p) {
      dfs(v, x, d + 1);
      sz[x] += sz[v];
    }
  }
}
void lca_init() {
  dfs_clock = 0;
  dfs(1, -1, 0);

  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 1; v <= n; ++v) {
      if (fa[k][v] < 0)
        fa[k + 1][v] = -1;
      else
        fa[k + 1][v] = fa[k][fa[k][v]];
    }
  }
}
int get_lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < mxlg; ++k) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }

  if (u == v) return u;

  for (int k = mxlg - 1; k >= 0; --k) {
    if (fa[k][v] != fa[k][u]) {
      v = fa[k][v];
      u = fa[k][u];
    }
  }
  return fa[0][u];
}
int get_dist(int x, int y) {
  return depth[x] + depth[y] - 2 * depth[get_lca(x, y)];
}
/*
先儿子更新父亲，再父亲更新儿子
因为父亲的最优值可能在另外的儿子处过来
*/
void dfs1(int x, int p) {
  rem[x] = sz[x];
  for (int i = 0; i < virtual_tree[x].size(); ++i) {
    int v = virtual_tree[x][i];
    if (v == p) continue;
    dfs1(v, x);
    if (!belong[v]) continue;
    int d1 = get_dist(belong[v], x);
    int d2 = get_dist(belong[x], x);
    if ((d1 < d2) || (d1 == d2 && belong[v] < belong[x]) || !belong[x]) {
      belong[x] = belong[v];
    }
  }
}
void dfs2(int x, int p) {
  for (int i = 0; i < virtual_tree[x].size(); ++i) {
    int v = virtual_tree[x][i];
    if (v == p) continue;
    int d1 = get_dist(belong[x], v);
    int d2 = get_dist(belong[v], v);
    if ((d1 < d2) || (d1 == d2 && belong[v] > belong[x]) || !belong[v]) {
      belong[v] = belong[x];
    }
    dfs2(v, x);
  }
}
void solve(int a, int b) {
  int x = b, mid = b;
  for (int k = mxlg - 1; k >= 0; --k) {
    if (depth[fa[k][x]] > depth[a]) {
      x = fa[k][x];
    }
  }
  rem[a] -= sz[x];
  if (belong[a] == belong[b]) {
    ans[belong[a]] += sz[x] - sz[b];
    return;
  }

  for (int k = mxlg - 1; k >= 0; --k) {
    int nxt = fa[k][mid];
    if (depth[nxt] <= depth[a]) continue;
    int d1 = get_dist(belong[a], nxt);
    int d2 = get_dist(belong[b], nxt);
    if (d1 > d2 || (d1 == d2 && belong[b] < belong[a])) {
      mid = nxt;
    }
  }
  ans[belong[a]] += sz[x] - sz[mid];
  ans[belong[b]] += sz[mid] - sz[b];
}
void build(vector<int>& V) {
  sort(V.begin(), V.end(), comp);

  int top = 0, tot = 0;
  if (belong[1] != 1) {
    S[top++] = 1;
    used[tot++] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    int v = V[i];
    int lca = get_lca(v, S[top - 1]);
    key_node[v] = 1;
    if (!vis[v]) {
      used[tot++] = v;
      vis[v] = 1;
    }
    if (!vis[lca]) {
      vis[lca] = 1;
      used[tot++] = lca;
    }
    if (lca != S[top - 1]) {
      while (top >= 2 && depth[S[top - 2]] >= depth[lca]) {
        virtual_tree[S[top - 2]].push_back(S[top - 1]);
        virtual_tree[S[top - 1]].push_back(S[top - 2]);
        --top;
      }

      if (S[top - 1] != lca) {
        virtual_tree[lca].push_back(S[top - 1]);
        virtual_tree[S[top - 1]].push_back(S[lca]);
        S[top - 1] = lca;
      }
    }
    S[top++] = v;
  }
  while (top > 1) {
    virtual_tree[S[top - 2]].push_back(S[top - 1]);
    virtual_tree[S[top - 1]].push_back(S[top - 2]);
    --top;
  }


  dfs1(1, -1);
  dfs2(1, -1);

  printf("!!!!!!!\n");
  return;

  for (int i = 0; i < tot; ++i) {
    int u = used[i];
    for (int j = 0; j < virtual_tree[u].size(); ++i) {
      int v = virtual_tree[u][i];
      solve(u, v);
    }
  }


  for (int x : V) {
    printf("%d\n", ans[x]);
  }

  // clear
  for (int i = 0; i < tot; ++i) {
    virtual_tree[used[i]].clear();
    rem[used[i]] = 0;
    belong[used[i]] = 0;
    ans[used[i]] = 0;
    key_node[used[i]] = 0;
    vis[used[i]] = 0;
  }
  key_nodes.clear();
}
void work() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    raw_tree[x].push_back(y);
    raw_tree[y].push_back(x);
  }

  lca_init();

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      int v;
      scanf("%d", &v);
      key_nodes.push_back(v);
    }

    for (int x : key_nodes) {
      belong[x] = x;
    }

    build(key_nodes);
  }
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  work();
}
