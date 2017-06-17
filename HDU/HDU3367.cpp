#include<iostream>
#include<cstdio>
#include<memory>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Edge {
    int u, v, w;
    void add_edge (int _u, int _v, int _w)
    {
        u = _u, v = _v, w = _w;
    }
} edge[maxn];
bool cmp (Edge a, Edge b)
{
    return a.w > b.w;
}

int N, M;
int fa[10010];
bool cir[10010];
void init (int n)
{
    for (int i = 0; i <= n; i++)  fa[i] = i;
}

int find (int x)
{
    if (x != fa[x])  fa[x] = find (fa[x]);
    return fa[x];
}

void merge (int a, int b)
{
    a = find (a);
    b = find (b);
    if (a != b)
        fa[a] = b;
}

int main (void)
{
    ios::sync_with_stdio (false);
    while (cin >> N >> M && (N + M)) {
        init (N);
        memset (edge, 0, sizeof (edge));
        memset (cir, 0, sizeof (cir));
        for (int i = 0; i < M; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            edge[i].add_edge (u, v, d);
        }
        sort (edge, edge + M, cmp);

        int res = 0;
        for (int i = 0; i < M; i++) {
            int a = find (edge[i].u), b = find (edge[i].v);
            int w = edge[i].w;
            if (a != b) {
                if (cir[a] && cir[b])  continue;
                else if (cir[a] || cir[b])  cir[a] = cir[b] = true;
                merge (a, b);
                res += w;
            } else {
                if (!cir[a]) {
                    cir[a] = true;
                    merge (a, b);
                    res += w;
                }
            }
        }
        cout << res << endl;
    }
}
