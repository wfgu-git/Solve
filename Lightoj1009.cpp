#include <bits/stdc++.h>
using namespace std;
const int maxm = 20000;
const int maxn = maxm * 2 + 20;
int n;
bool vis[maxn];
struct UFset {
  int n;
  int fa[maxn], rank[maxn];
  inline void init(int n) {
    this->n = n;
    for (int i = 0; i < maxn; ++i) {
      rank[i] = 0;
      fa[i] = i;
    }
  }
  inline int find(int x) {
    if (x != fa[x]) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }
  inline int unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return 0;

    // if (rank[a] < rank[b]) {
    //   fa[a] = b;
    // } else {
    //   fa[b] = a;
    //   if (rank[a] == rank[b]) ++rank[a];
    // }
    fa[b] = a;
    rank[a] += rank[b];
    return 1;
  }
} ufst;
void work(int kase) {
  set<int> num;
  scanf("%d", &n);
  ufst.init(n);
  for (int i = 0; i < n; ++i) {
    static int u, v;
    scanf("%d%d", &u, &v);
    if (!ufst.rank[u]) ufst.rank[u] = 1;
    if (!ufst.rank[v]) ufst.rank[v] = 1;
    num.insert(u); num.insert(v);
    ufst.unite(u, v + maxm);
    ufst.unite(u + maxm, v);
  }
  int ans = 0;
  memset(vis, 0, sizeof(vis));
  for (set<int>::iterator it = num.begin(); it != num.end(); ++it) {
    int a = *it;
    int x = ufst.find(a);
    int y = ufst.find(a + maxm);
    if (vis[x] || vis[y]) continue;
    ans += max(ufst.rank[x], ufst.rank[y]);
    vis[x] = vis[y] = true;
  }
  printf("Case %d: %d\n", kase, ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
