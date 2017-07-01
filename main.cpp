//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int manx = 50000 + 5;
typedef pair < int, int > pii;
vector < vector < int > > g;
vector < vector < pii > > qry;
bool vis[maxn];
int fa[maxn];
int up[maxn];
int down[maxn];
int Max[maxn];
int Min[maxn];
int w[maxn];
int ans[maxn];
int clr_init(const int &n) {
    g.resize(n + 2);
    g.clear();
    qry.resize(n + 2);
    qry.clear();
    memset(vis, 0, sizeof(vis));
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));
    memset(Max, 0, sizeof(Max));
    memset(Min, 0, sizeof(Min));
}
int fnd(int x) {
    if (x != fa[x]) {
        int t = fa[x];
        fa[x] = fnd(fa[x]);
        up[x] = max(max(up[x], up[t]), Max[t] - Min[x]);
        down[x] = max(max(down[x], down[t]), Max[x] - Min[t]);
        Max[x] = max(Max[x], Max[t]);
        Min[x] = min(Min[x], Min[t]);
    }
    return fa[x];
}
void tarjan(int u) {
    vis[u] = true;
    fa[u] = u;
    for (int i = 0; i < (int)g[u].size(); i++) {
        const v = g[u][i];
        if (!vis[v]) {
            dfs(v);
            fa[v] = u;
        }
    }
    for (int i = 0; i < (int)qry[u].size(); i++) {
        const int v = qry[u][i].first;
        const int now = qry[u][i].second;
        if (!vis[v]) continue;

    }
}
int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        clr_init(n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            Max[i] = a[i];
            Min[i] = a[i];
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            qry[u].push_back({v, i});
            qry[v].push_back({u, i});
        }
        tarjan(1, 0);

        for (int i = 0; i < n; i++) {

        }
    }
    return 0;
}
