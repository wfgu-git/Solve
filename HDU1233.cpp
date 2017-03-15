#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <cctype>
#include <climits>
#include <utility>
#include <memory>
#include <functional>
using namespace std;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,c,b) scanf("%d%d%d",&a,&b,&c)
#define pt(a) printf("%d\n",a)
#define ptlld(a) printf("%lld\n",a)
#define mp(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 110;
int cost[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int n, m;

int Prim()
{
    mset(used, 0);
    for(int i = 1; i <= n; i++) {
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[1] = 0;
    int res = 0;

    while(true) {
        int v = -1;
        for(int u = 1; u <= n; u++) {
            if(!used[u] && (v == -1 || mincost[u] < mincost[v]))
                v = u;
        }

        if(v == -1)  break;
        used[v] = true;
        res += mincost[v];

        for(int u = 1; u <= n; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while(~scanf("%d", &n) && n) {
        mset(cost, 0), mset(mincost, 0);
        m = n * (n - 1) / 2;
        int u, v, d;
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &d);
            cost[u][v] = d;
            cost[v][u] = d;
        }
        printf("%d\n", Prim());
    }
    return 0;
}
