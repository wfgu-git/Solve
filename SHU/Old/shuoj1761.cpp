#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
struct Edge {int u, v, next;} edge[maxn];
struct Query {int u, v, id, next;} qry[maxn];
int tot, qtot;
bool vis[maxn];
int fa[maxn];
int head[maxn], qhead[maxn];
int ans[maxn];
void add_edge(int u, int v)
{
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void add_qry(int u, int v, int id)
{
    qry[qtot].u = u;
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
void init()
{
    tot = 0;
    qtot = 0;
    memset(fa, 0, sizeof(fa));
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    memset(qhead, -1, sizeof(qhead));
}
void Lca(int u, int p)
{
    vis[u] = true;
    fa[u] = u;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == p) continue;
        Lca(v, u);
        fa[v] = u;
    }
    for (int i = qhead[u]; i != -1; i = qry[i].next) {
        int v = qry[i].v;
        int now = qry[i].id;
        if (v == p) continue;
        if (vis[v]) {
            ans[now] = fnd(v);
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        init();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add_qry(u, v, i);
            add_qry(v, u, i);            
        }
        Lca(0, 0);
        printf("Case %d:\n", cas);
        for (int i = 0; i < m; i++) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}