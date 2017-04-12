#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
#include<climits>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1010;
const int INF = 0x3f3f3f3f;
bool used[maxn];
int mincost[maxn];
int cost[maxn][maxn];

int prim(int n)
{
    for(int i = 0; i < n; i++) {
        used[i] = false;
        mincost[i] = cost[0][i];
    }
    used[0] = true;
    int ans = -INF;
    while(true) {
        int v = -1;
        int minc = INF;
        for(int u = 0; u < n; u++)
            if(!used[u] && (v == -1 || mincost[u] < minc))
                v = u, minc = mincost[u];

        if(v == -1)  break;
        used[v] = true;
        ans = max(ans, minc);
        if(v == n - 1) break;
        for(int u = 0; u < n; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }

    }
    return ans;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cost[i][j] = INF;
            }
        }
        while(m--) {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            u--, v--, d = -d;
            cost[u][v] = d;
            cost[v][u] = d;
        }
        printf("Scenario #%d:\n%d\n\n", ++kase, -1 * prim(n));
    }
    return 0;
}
