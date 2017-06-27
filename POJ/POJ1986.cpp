#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5;
const int logmaxn = 20;
int tot, head[maxn + 5];
struct Edge {
    int v, d, next;
}edge[maxn * 2 + 5];
void add_edge(int u, int v, int d)
{
    edge[tot].v = v;
    edge[tot].d = d;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int fa[maxn][logmaxn];
int dis[maxn];
int dep[maxn];
int root;
void clr()
{
    tot = 0;
    root = 1;
    memset(head, -1, sizeof(head));
    memset(fa, -1, sizeof(fa));
    memset(dis, 0, sizeof(dis));
    memset(dep, 0, sizeof(dep));
}
void dfs(int u, int p, int depth)
{
    fa[u][0] = p;
    dep[u] = depth;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        const int v = edge[i].v;
        const int d = edge[i].d;
        if (v == p) continue;
        dis[v] = dis[u] + d;
        dfs(v, u, depth + 1);
    }
}
void init(const int &n)
{
    fa[root][0] = -1;
    dis[root] = 0;
    dfs(root, 0, 0);
    for (int k = 0; k + 1 < logmaxn; k++) {
        for (int v = 1; v <= n; v++) {
            if (fa[v][k] < 0) fa[v][k + 1] = -1;
            else fa[v][k + 1] = fa[fa[v][k]][k]; 
        }
    }
}
int lca(int u, int v)
{
    int uu = u;
    int vv = v;
    if (dep[u] > dep[v]) swap(u, v);
    for (int k = 0; k < logmaxn; k++) {
        if ((dep[v] - dep[u]) >> k & 1) 
            v = fa[v][k];
    }

    int _lca;
    if (u == v) _lca = u;
    else {
        for (int k = logmaxn - 1; k >= 0; k--) {
            if (fa[v][k] != fa[u][k]) {
                v = fa[v][k];
                u = fa[u][k];
            }
        }
        _lca = fa[u][0];
    }
    return dis[uu] + dis[vv] - 2 * dis[_lca];
}
int main()
{
    int n, m, k;
    while (scanf("%d%d", &n, &m) == 2) {
        clr();
        for (int i = 0; i < m; i++) {
            char dir[5];
            int u, v, d;
            scanf("%d%d%d%s", &u, &v, &d, dir);
            add_edge(u, v, d);
            add_edge(v, u, d);
        }
        init(n);

        // for (int i = 1; i <= n; i++) {
        //     cout << "dis " << i << " == " << dis[i] << endl;
        // }
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", lca(u, v));
        }
    }
    return 0;
}