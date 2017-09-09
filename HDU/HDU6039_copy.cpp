#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
const int INF = ~0U >> 1;
const double ln2 = log(2.);
const int N = 100010, M = N << 2;
int n, m, k, d[N], f[N];
struct Edge {
  int v, w, r;
};
vector<int> v[N];
vector<Edge> E[N];
bool mark[N];
int rad[N], l[N], r[N], L[N], R[N], rt[N];
int log2(int x) {
  int d;
  while (x >>= 1) d++;
  return d;
}
namespace Segment_Tree {
int tot;
struct node {
  int l, r, a, b, tag, val;
} T[M];
void build(int, int);
void Initialize(int n) {
  tot = 0;
  build(1, n);
}
void addtag(int x, int tag) {
  T[x].tag += tag;
  T[x].val += tag;
}
void pb(int x) {
  if (T[x].l) {
    addtag(T[x].l, T[x].tag);
    addtag(T[x].r, T[x].tag);
  }
  T[x].tag = 0;
}
void up(int x) { T[x].val = max(T[T[x].l].val, T[T[x].r].val); }
void build(int l, int r) {
  int x = ++tot;
  T[x].a = l;
  T[x].b = r;
  T[x].tag = T[x].l = T[x].r = T[x].val = 0;
  if (l == r) {
    T[x].val = d[l];
    return;
  }
  int mid = (l + r) >> 1;
  T[x].l = tot + 1;
  build(l, mid);
  T[x].r = tot + 1;
  build(mid + 1, r);
  up(x);
}
void change(int x, int a, int b, int p) {
  if (T[x].a >= a && T[x].b <= b) {
    addtag(x, p);
    return;
  }
  if (T[x].tag) pb(x);
  int mid = (T[x].a + T[x].b) >> 1;
  if (mid >= a && T[x].l) change(T[x].l, a, b, p);
  if (mid < b && T[x].r) change(T[x].r, a, b, p);
  up(x);
}
int query(int x, int a, int b) {
  if (T[x].a >= a && T[x].b <= b) return T[x].val;
  if (T[x].tag) pb(x);
  int mid = (T[x].a + T[x].b) >> 1;
  int res = -INF;
  if (mid >= a && T[x].l) res = max(res, query(T[x].l, a, b));
  if (mid < b && T[x].r) res = max(res, query(T[x].r, a, b));
  return res;
}
}
int cnt;
void dfs(int Rt, int fx, int x, int _d) {
  rt[x] = Rt;
  d[l[x] = ++cnt] = _d;
  for (int i = 0; i < E[x].size(); i++) {
    Edge e = E[x][i];
    if (e.v == fx) {
      mark[e.w] = 1;
    } else {
      L[e.w] = min(L[e.w], cnt + 1);
      dfs(Rt, x, e.v, _d + e.r);
      R[e.w] = max(R[e.w], cnt);
    }
  }
  r[x] = cnt;
}
void print(int k) { printf("%.3f\n", k * ln2); }
int sf(int x) { return f[x] == x ? x : f[x] = sf(f[x]); }
int Cas = 1, op, x, y;
int main() {
  while (~scanf("%d%d%d", &n, &m, &k)) {
    for (int i = 1; i <= n; i++) {
      f[i] = i;
      L[i] = INF, R[i] = rt[i] = 0;
      mark[i] = 0;
      v[i].clear();
      E[i].clear();
      scanf("%d", &rad[i]);
      rad[i] = log2(rad[i]);
    }
    while (m--) {
      scanf("%d%d%d", &op, &x, &y);
      if (op - 1) {
        f[sf(x)] = sf(y);
      } else {
        v[x].push_back(y);
        v[y].push_back(x);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 0; k < v[i].size(); k++) {
        int j = v[i][k];
        E[sf(i)].push_back((Edge){sf(j), i, rad[i] - rad[j]});
      }
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (sf(i) == i && !rt[sf(i)]) dfs(f[i], 0, f[i], 0);
    }
    using namespace Segment_Tree;
    Initialize(cnt);
    printf("Case #%d:\n", Cas++);
    while (k--) {
      scanf("%d%d%d", &op, &x, &y);
      y = log2(y);
      if (op - 1) {
        x = sf(x);
        print(y - query(1, l[x], l[x]) + query(1, l[rt[x]], r[rt[x]]));
      } else {
        int fx = sf(x), d = y - rad[x];
        if (mark[x]) change(1, l[fx], r[fx], -d);
        if (L[x] <= R[x]) change(1, L[x], R[x], d);
        rad[x] = y;
      }
    }
  }
  return 0;
}
