/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;


int N, Q;
vector<int> G[maxn];
vector<pii> Qs[maxn];
int val[maxn];
int ans[maxn];
struct Node {
  int ch[2];
} st[maxn * 64];
int tot;
void init() {
  tot = 1;
  st[0].ch[0] = st[0].ch[1] = 0;
}
int newnode() {
  st[tot].ch[0] = st[tot].ch[1] = 0;
  return tot++;
}
void insert(int& o, int x) {
  if (o == 0) o = newnode();

  int tid;
  for (int i = 31; i >= 0; --i) {
    tid = 0;
    if (x & (1 << i)) tid = 1;
    if (!st[o].ch[tid]) {
      st[o].ch[tid] = newnode();
    }
    o = st[o].ch[tid];
  }
}
int query(int o, int x) {
  int now = o;
  int ret = 0;
  int tid;
  for (int i = 31; i >= 0; --i) {
    tid = 0;
    if (x & (1 << i)) tid = 1;
    if (st[now].ch[tid ^ 1]) {
      now = st[now].ch[tid ^ 1];
      ret |= (1 << i);
    } else {
      now = st[now].ch[tid];
    }
  }
  return ret;
}
void unite(int& p, int& q) {
  if (p == 0) {
    p = q;
    return;
  }
  if (st[q].ch[0]) unite(st[p].ch[0], st[q].ch[0]);
  if (st[q].ch[1]) unite(st[p].ch[1], st[q].ch[1]);
}
int dfs(int u) {
  int rt = 0;
  insert(rt, val[u]);
  for (int& v : G[u]) {
    int t = dfs(v);
    unite(rt, t);
  }
  for (int i = 0; i < Qs[u].size(); ++i) {
    ans[Qs[u][i].second] = query(rt, Qs[u][i].first);
  }
  return rt;
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &N, &Q) != EOF) {
    init();
    for (int i = 1; i <= N; ++i) {
      G[i].clear();
      Qs[i].clear();
      scanf("%d", val + i);
    }
    for (int i = 2; i <= N; ++i) {
      int p;
      scanf("%d", &p);
      G[p].push_back(i);
    }
    for (int i = 0; i < Q; ++i) {
      int v, x;
      scanf("%d%d", &v, &x);
      Qs[v].push_back({x, i});
    }
    dfs(1);
    for (int i = 0; i < Q; ++i) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
