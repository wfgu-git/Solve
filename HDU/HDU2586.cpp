#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
const int maxn= 40005;
vector < vector < pii > > g;
vector < vector < pii > > qry;
bool vis[maxn];
int fa[maxn];
int dis[maxn];
int ans[maxn];
int fnd(int x)
{
    if (x != fa[x]) fa[x] = fnd(fa[x]);
    return fa[x];
}
void tarjan(int u, int p) 
{
    vis[u] = 1;
    fa[u] = u;
    for (auto x : g[u]) {
        int v = x.first;
        int d = x.second;
        if (v == p) continue;
        dis[v] = dis[u] + d;
        tarjan(v, u);
        fa[v] = u;
    }
    for (auto q : qry[u]) {
        int v = q.first;
        int now = q.second;
        if (vis[v]) {
            ans[now] = dis[u] + dis[v] - 2 * dis[fnd(v)];
        }
    }
}
void init(const int &n, const int &m) {
    g.resize(n + 2);
    g.clear();
    qry.resize(n + 2);
    qry.clear();
    memset(vis, 0, sizeof(vis));
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n, m);
        for (int i = 1; i < n; i++) {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            g[u].push_back({v, d});
            g[v].push_back({u, d});
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            qry[u].push_back({v, i});
            qry[v].push_back({u, i});
        }

        tarjan(1, 0);

        for (int i = 0; i < m; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}