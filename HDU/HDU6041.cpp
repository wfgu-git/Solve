/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll moder = 1LL << 32;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

int n, m, K;
int head[maxn], tot;
vector<int> cir[maxn];
bool vis[maxn];
int fa[maxn], g[maxn];
int block;
struct INFO {
  int s, b;
  INFO(int _s, int _b) : s(_s), b(_b) {}
  bool operator < (const INFO& rhs) const {
    return s < rhs.s;
  }
} ;
struct Edge {int to, next, cost, vis;} edge[maxn * 6];
void add_edge(int u, int v, int d) {
  edge[tot] = {v, head[u], d, 0};
  head[u] = tot++;
}
void dfs(int u) {
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (edge[i].vis) continue;
    edge[i].vis = 1;
    edge[i ^ 1].vis = 1;
    if (vis[v]) {
      int p = u;
      do {
        cir[block].push_back(edge[g[p]].cost);
        p = fa[p];
      } while(p != v);
      cir[block].push_back(edge[i].cost);
      ++block;
    } else {
      vis[v] = 1;
      fa[v] = u;
      g[v] = i;
      dfs(v);
    }
  }
}
void work(int kase) {
  tot = 0;
  block = 0;
  memset(head, -1, sizeof(head));

  ll sum = 0;
  for (int u, v, w, i = 0; i < m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    sum += w;
    add_edge(u, v, w);
    add_edge(v, u ,w);
  }
  scanf("%d", &K);

  for (int i = 0; i < n; ++i) cir[i].clear();
  memset(vis, 0, sizeof(vis));
  block = 0;
  vis[1] = 1;
  dfs(1);

  vector<int> ret = {0}, tmp;
  priority_queue<INFO> Q;
  for (int i = 0; i < block; ++i) {
    // sort(cir[i].begin(), cir[i].end());
    while (!Q.empty()) Q.pop();
    tmp.clear();

    for (int& x : cir[i]) {
      Q.push(INFO(x + ret[0], 0));
    }
    while (tmp.size() < K && !Q.empty()) {
      INFO now = Q.top(); Q.pop();
      tmp.push_back(now.s);
      int b = now.b;
      if (b + 1 < ret.size()) {
        Q.push(INFO(now.s - ret[b] + ret[b + 1], b + 1));
      }
    }
    ret = tmp;
  }
  ll ans = 0;
  for (int i = 0; i < ret.size(); ++i) {
    ans += 1LL * (i + 1) * (sum - ret[i]) % moder;
    ans %= moder;
  }
  printf("Case #%d: %lld\n", kase, ans);
}
int kase = 0;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &n, &m) != EOF) {
    work(++kase);
  }
}
