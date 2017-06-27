#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 50000;
const int logmaxn = 20 + 1;
vector < int > g[maxn + 5];
int w[maxn];
int depth[maxn];
int fa[maxn][logmaxn];
int Max[maxn][logmaxn], Min[maxn][logmaxn];
int up[maxn][logmaxn], down[maxn][logmaxn];

void dfs(int u, int p, int d)
{
    fa[u][0] = p;
    depth[u] = d;
    up[u][0] = max(w[p] - w[u], 0);
    down[u][0] = max(w[u] - w[p], 0);
    Max[u][0] = max(w[u], w[p]);
    Min[u][0] = min(w[u], w[p]); 

    for (int i = 0; i < (int)g[u].size(); i++) {
        const int v = g[u][i];
        if (v != p)
            dfs(v, u, d + 1);
    }
}
void init(const int &n)
{
    memset(Max, 0, sizeof(Max));
    memset(Min, 0, sizeof(Min));

    dfs(1, 0, 0);

    for (int k = 0; k + 1 < logmaxn; k++) {
        for (int v = 0; v <= n; v++) {
            if (fa[v][k] == 0) fa[v][k + 1] = 0;
            else {
                fa[v][k + 1] = fa[fa[v][k]][k];
                int t = fa[v][k];
                Max[v][k + 1] = max(Max[v][k], Max[t][k]);
                Min[v][k + 1] = min(Min[v][k], Min[t][k]);
                up[v][k + 1] = max(max(up[v][k], up[t][k]), Max[t][k] - Max[v][k]);
                down[v][k + 1] = max(max(down[v][k], down[t][k]), Max[v][k] - Max[t][k]);
            }
        }
    }
}
int lca(int u, int v)
{
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < logmaxn; k++) {
        if ((depth[v] - depth[u]) >> k & 1) 
            v = fa[v][k];
    } 
    if (u == v) return u;
    for (int k = logmaxn - 1; k >= 0; k--) {
        if (fa[u][k] != fa[v][k]) {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}
int get_up(int x, int k, int &min_price)
{
    min_price = 0x3f3f3f3f;
    int pre = 0x3f3f3f3f;
    int profit = 0;
    for (int i = logmaxn; i >= 0; i--) {
        if ((k >> i) & 1) {
            min_price = min(min_price, Min[x][i]);
            profit = max(profit, up[x][i]);
            profit = max(profit, Max[x][i] - pre);
            pre = min(pre, Min[x][i]);
            x = fa[x][i];
        }
    }
    return profit;
}
int get_down(int x, int k, int &max_price)
{
    max_price = 0;
    int pre = 0;
    int profit = 0;
    for (int i = logmaxn; i >= 0; i--) {
        if ((k >> i) & 1) {
            max_price= max(max_price, Max[x][i]);
            profit = max(profit, down[x][i]);
            profit = max(profit, pre - Min[x][i]);
            pre = max(pre, Max[x][i]);
            x = fa[x][i];
        }
    }
    return profit;
}
int main()
{
    int n, m, q;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) 
            scanf("%d", &w[i]);
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        init(n);
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &u, &v);
            int t = lca(u, v);
            int min_price, max_price;
            int max_up = get_up(u, depth[u] - depth[t], min_price);
            int max_down = get_down(v, depth[t] - depth[v], max_price);
            int ans = max(max_price - min_price, max(max_up, max_down));
            printf("%d\n", ans);
        }
    }
    return 0;
}