// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 10000;
const int logmaxn = 15;
int dep[maxn];
int fa[maxn][logmaxn];
bool vis[maxn];
int root;
vector < vector < int > > g;
void get_root(int n, int &root)
{
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
}
void dfs(int u, int p)
{
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        // if (v == p) continue;
        dfs(v, u);
    } 
}
void init(const int &n, int root)
{
    memset(vis, 0, sizeof(vis));
    dep[root] = 0;
    dfs(root, 0);
    for (int k = 0; k + 1 < logmaxn; k++) {
        for (int v = 1; v <= n; v++) {
            if (fa[v][k] == 0)  fa[v][k + 1] = 0;
            else fa[v][k + 1] = fa[fa[v][k]][k];
        }
    }
}
int lca(int u, int v)
{
    if (dep[u] > dep[v]) swap(u, v);
    for (int k = 0; k < logmaxn; k++) {
        if ((dep[v] - dep[u]) >> k & 1) {
            v = fa[v][k];
        }
    }

    if (v == u) return u;

    for (int k = logmaxn - 1; k >= 0; k--) {
        if (fa[u][k] != fa[v][k]) {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        memset(vis, 0, sizeof(vis));
        int n;
        scanf("%d", &n);
        g.resize(n + 2);
        g.clear();
        int u, v;
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            vis[v] = 1;
            g[u].push_back(v);
            // g[v].push_back(u);
        }
        get_root(n, root);
        init(n, root);

        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}