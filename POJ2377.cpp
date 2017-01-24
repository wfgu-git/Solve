#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
struct Node {
    int from, to;
    int cost;
} edge[20010];
bool cmp (Node a, Node b)
{
    return a.cost > b.cost;
}

int fa[1010];
void init (int n)
{
    for (int i = 0; i <= n; i++)
        fa[i] = i;
}

int findfa (int x)
{
    if(x!=fa[x])  fa[x]=findfa(fa[x]);
    return fa[x];
}

int main (void)
{
    ios::sync_with_stdio (false);
    int n, m;
    int cost = 0, cnt = 0;
    cin >> n >> m;
    init (n);
    for (int i = 1; i <= m; i++)
        cin >> edge[i].from >> edge[i].to >> edge[i].cost;
    sort (edge + 1, edge + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        int x = findfa (edge[i].from);
        int y = findfa (edge[i].to);
        if (x == y)
            continue;
        fa[y] = x;
        cnt++;
        cost += edge[i].cost;
    }
    if (cnt == n - 1)
        cout << cost << endl;
    else
        cout << -1 << endl;
    return 0;
}
