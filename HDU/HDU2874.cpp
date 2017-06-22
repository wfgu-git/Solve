#include <cstdio>
#include <cstring>
using namespace std;

struct Edge {
    int v, d, next;
} g[20001];
struct Query {
    int v, id, next;
} qry[2000001];
int n, m, q;
int fa[10001];
int vis[10001];
int head[10001], qhead[10001];
int ans[1000001], dis[10001];
int tot, qtot;
inline void add_edge(int u, int v, int d)
{
    g[tot].v = v;    
    g[tot].d = d;
    g[tot].next = head[u];
    head[u] = tot++;
}
inline void add_qry(int u, int v, int id)
{
    qry[qtot].v = v;
    qry[qtot].id = id;
    qry[qtot].next = qhead[u];
    qhead[u] = qtot++;
}
int fnd(int x)
{
    if (fa[x] != x) fa[x] = fnd(fa[x]);
    return fa[x];
}
void lca(const int &u, const int &p)
{
    fa[u] = u;
    vis[u] = 1;
    int i, v, d;
    for (i = head[u]; i != -1; i = g[i].next) {
        v = g[i].v;
        d = g[i].d;
        if (v == p) continue;

        dis[v] = dis[u] + d;
        lca(v, u);
        fa[v] =u;
    }

    for (i = qhead[u]; i != -1; i = qry[i].next) {
        v = qry[i].v;
        d = qry[i].id;
        if (v == p) continue;

        if (vis[v]) {
            if (dis[v] != -1) {
                ans[d] = dis[u] + dis[v] - 2 * dis[fnd(v)];
            } else {
                ans[d] = -1;
            }
        }
    }
}
void solve(const int &n)
{
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            memset(dis, -1, sizeof(dis));
            lca(i, i);
        }
}
void init(const int &n)
{
    tot = 0;
    qtot = 0;
    memset(head, -1, sizeof(head));
    memset(qhead, -1, sizeof(qhead));
    memset(vis, 0, sizeof(vis));
    memset(dis, -1, sizeof(dis));
}
int main()
{
    while (~scanf("%d%d%d", &n, &m, &q)) {
        init(n);
        int i;
        int u, v, d;
        for (i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &d);
            add_edge(u, v, d);
            add_edge(v, u, d);
        }
        for (i = 0; i < q; i++) {
            scanf("%d%d", &u, &v);
            add_qry(u, v, i);
            add_qry(v, u, i);
        }
        solve(n);
        for (i = 0; i < q; i++) {
            if (ans[i] == -1)
                printf("Not connected\n");
            else
                printf("%d\n", ans[i]);
        }
    }
    return 0;
}
