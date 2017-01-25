#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 300010;
struct Edge {
    int from, to;
    int cost;
} edge[maxn];

bool cmp (Edge a, Edge b)
{
    return a.cost > b.cost;
}
int fa[maxn];

void init (int n)
{
    for (int i = 0; i < n; i++)
        fa[i] = i;
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
        fa[b] = a;
}

int main (void)
{
    int T;
    scanf ("%d", &T);
    while (T--) {
        int n, m;
        scanf ("%d%d", &n, &m);
        init (n);
        for (int i = 0; i < m; i++) {
            scanf ("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].cost);
        }
        sort (edge, edge + m, cmp);
        int res;
        int cnt = 0;
        bool flag = false;
        if (find (edge[0].from) != find (edge[0].to)) {
            merge (edge[0].from, edge[0].to);
            res = edge[0].cost;
            cnt++;
        }
        for (int i = 1; i < m; i++) {
            if (find (edge[i].from) != find (edge[i].to)) {
//                if (!flag) {
//                    merge (edge[i].from, edge[i].to);
//                    res = edge[i].cost;
//                    cnt++;
//                    flag = true;
//                    continue;
//                } else {
                merge (edge[i].from, edge[i].to);
                res &= edge[i].cost;
                cnt++;
//                }
            }
        }
        if (cnt == n - 1)
            printf ("%d\n", res);
        else
            printf ("0\n");
    }
    return 0;
}
