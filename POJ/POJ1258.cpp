#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
int cost[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int n;

int Prim()
{
    memset (used, 0, sizeof (used));
    for (int i = 0; i < n; i++) {
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[0] = 0;
    int ans = 0;

    while (true) {
        int v = -1;
        for (int u = 0; u < n; u++) {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
                v = u;
        }
        if (v == -1) break;
        used[v] = true;
        ans += mincost[v];

        for (int u = 0; u < n; u++) {
            mincost[u] = min (mincost[u], cost[v][u]);
        }
    }
    return ans;
}
int main (void)
{
    while (cin >> n) {
        memset (cost, 0, sizeof (cost));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cost[i][j];
            }
        }
        cout<<Prim()<<endl;
    }
    return 0;
}

