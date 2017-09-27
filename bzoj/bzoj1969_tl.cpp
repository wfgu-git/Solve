#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 3e5 + 7;

vector<int>G[N];
vector<pair<int, int> > edges;
vector<int> g[N];
bool is_cut[N];
map<pair<int, int>, bool > is_del;
int dfn[N], low[N], fa[N], L[N], R[N];
int f[N][21], dep[N];
int Index = 0, id = 0;
void init()
{
    is_del.clear();
    for (int i = 0; i < N; i++)
        G[i].clear(), g[i].clear(), fa[i] = i;
    edges.clear();
    memset(dfn, 0, sizeof(dfn));
    memset(is_cut, 0, sizeof(is_cut));
    memset(low, 0, sizeof(low));
    Index = id = 0;
}
void add_edge(int u, int v)
{
    edges.push_back(make_pair(u, v));
    G[u].push_back(edges.size() - 1);
    edges.push_back(make_pair(v, u));
    G[v].push_back(edges.size() - 1);
}
void tarjan(int u, int Fa)
{
    dfn[u] = low[u] = ++ Index;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = edges[G[u][i]].second;
        if (v == Fa || is_del.count(make_pair(u, v)))
            continue;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                is_cut[G[u][i] ^ 1] = is_cut[G[u][i]] = 1;
        }
        else low[u] = min(low[u], dfn[v]);
    }
}
int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    if (dep[u] > dep[v])
        swap(u, v);
    fa[v] = u;
}
void Create_Tree(int n)
{
    for (int i = 1; i <= n; i++)
    {
        sort(G[i].begin(), G[i].end());
        G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);
    for (int i = 0; i != edges.size(); i ++)
        if (!is_cut[i] && !is_del.count(make_pair(edges[i].first, edges[i].second)))
            merge(edges[i].first, edges[i].second);
    for (int i = 0; i != edges.size(); i++)
        if (is_cut[i] && !is_del.count(make_pair(edges[i].first, edges[i].second)))
            g[find(edges[i].first)].push_back(find(edges[i].second));
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
        vector<int> :: iterator it = unique(g[i].begin(), g[i].end());
        g[i].erase(it, g[i].end());
    }
    // for (int i = 1; i <= n; i++)
    // {
    //  cout << "*" << i;
    //  for (int j = 0; j < g[i].size(); j++)
    //      cout << "---->" << g[i][j];
    //  cout << endl;
    // }
}
void dfs(int u, int fa, int d)
{
    L[u] = ++ id;
    dep[u] = d, f[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = 0; i != g[u].size(); i ++)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        dfs(v, u, d + 1);
    }
    R[u] = id;
}
int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--)
        if (dep[f[u][i]] >= dep[v])
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
struct Tree
{
    int l, r;
    int sum, vis;
} t[N * 4];
void push_down(int step)
{
    if (!t[step].vis)
        return;
    t[step * 2].vis += t[step].vis;
    t[step * 2 + 1].vis += t[step].vis;
    t[step * 2].sum += (t[step * 2].r - t[step * 2].l + 1) * t[step].vis;
    t[step * 2 + 1].sum += (t[step * 2 + 1].r - t[step * 2 + 1].l + 1) * t[step].vis;
    t[step].vis = 0;
}
void build(int l, int r, int step)
{
    t[step].l = l, t[step].r = r, t[step].vis = 0, t[step].sum = 0;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(l, mid, step * 2);
    build(mid + 1, r, step * 2 + 1);
}
void update(int l, int r, int val, int step)
{
    if (t[step].l == l && r == t[step].r)
    {
        t[step].vis += val;
        t[step].sum += val * (t[step].r - t[step].l + 1);
        return;
    }
    int mid = (t[step].l + t[step].r) / 2;
    push_down(step);
    if (r <= mid)
        update(l, r, val, step * 2);
    else if (l > mid)
        update(l, r, val, step * 2 + 1);
    else update(l, mid, val, step * 2), update(mid + 1, r, val, step * 2 + 1);
}
int query(int x, int step)
{
    if (t[step].l == t[step].r)
        return t[step].sum;
    int mid = (t[step].l + t[step].r) / 2;
    push_down(step);
    if (x <= mid)
        return query(x, step * 2);
    else if (x > mid)
        return query(x, step * 2 + 1);
}
void del(int u, int v)
{
    u = find(u), v = find(v);
    int anc = find(lca(u, v));
    while (find(u) != find(anc))
    {
        update(L[find(u)], R[find(u)], -1, 1);
        merge(find(u), f[find(u)][0]);
    }
    while (find(v) != find(anc))
    {
        update(L[find(v)], R[find(v)], -1, 1);
        merge(find(v), f[find(v)][0]);
    }
}
int Get_Ans(int u, int v)
{
    u = find(u), v = find(v);
    int anc = find(lca(u, v));
    return query(L[u], 1) + query(L[v], 1) - 2 * query(L[anc], 1);
}
vector<pair<bool, pair<int, int> > > Q;
vector<int> ac;
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        init();
        ac.clear();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        Q.clear();
        int op, x, y;
        while (~scanf("%d", &op))
        {
            if (op == -1)
                break;
            scanf("%d%d", &x, &y);
            Q.push_back(make_pair(op, make_pair(x, y)));
            if (!op)
            {
                is_del[make_pair(x, y)] = 1;
                is_del[make_pair(y, x)] = 1;
            }
        }
        Create_Tree(n);
        dfs(find(1), find(1), 0);
        build(1, n, 1);
        for (int i = 1; i <= n; i++)
            if (find(i) == i)
                update(L[i], L[i], dep[i], 1);
        for (int i = Q.size() - 1; i >= 0; i --)
        {
            op = Q[i].first;
            x = find(Q[i].second.first);
            y = find(Q[i].second.second);
            if (!op)
                del(x, y);
            else
                ac.push_back(Get_Ans(x, y));
        }
        reverse(ac.begin(), ac.end());
        for (int i = 0; i != ac.size(); i++)
            printf("%d\n", ac[i]);
    }
}
