#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
#define INF 0x3f3f3f3f
const int N = 505;

int Map[N][N];
int n;
int a[N], b[N], c[N], d[N];
int deg[N];
struct Node
{
    int sell, buy;
    int d;
    bool operator < (const  Node & rhs)const
    {
        return d > rhs.d || (d == rhs.d && (deg[sell] < deg[sell]));
    }
} v[N * N];
void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
          if (i == k) continue;
            if (Map[i][k])
                for (int j = 1; j <= n; j++)
                {
                    if (Map[k][j])
                    {
                        if (Map[i][j] > Map[i][k] + Map[k][j])
                            Map[i][j] = Map[i][k] + Map[k][j];
                    }
                }
        }
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m)
    {
        memset(v, -INF, sizeof(v));
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
            v[tot++] = {i, i, c[i] - a[i]};
        }
        memset(Map, 0, sizeof(Map));
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < m; i++)
        {
            int u, v, d;
            cin >> u >> v >> d;
            deg[u] ++, deg[v] ++;
            if (u == v)
                continue;
            if (!Map[u][v])
                Map[u][v] = Map[v][u] = d;
            else
                Map[u][v] = min(Map[u][v], d), Map[v][u] = min(Map[v][u], d);
        }
        floyd();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && Map[i][j])
                {
                    v[tot++] = {i, j, c[i] - Map[j][i] - a[j]}; // sell buy d
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < tot; i++)
        {
          sort(v, v + tot);
            int u = v[i].buy, vv = v[i].sell, dd = v[i].d;
            int can = min(b[u], d[vv]);
            ans += 1LL * can * dd;
            b[u] -= can, d[vv] -= can;
        }
        cout << ans << endl;
    }
}
