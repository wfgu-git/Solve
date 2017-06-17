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

const int maxn = 5050;
int fa[110];
void init(int n)
{
    for(int i = 0; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    if(x != fa[x])  fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
        return ;
    fa[a] = b;
}
struct Edge {
    int from, to;
    int value;
} edge[maxn];
bool cmp(Edge a, Edge b)
{
    return a.value < b.value;
}
int n, m;
//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while(~scanf("%d", &n) && n) {
        mset(edge, 0);
        init(n);
        m = n * (n - 1) / 2;
        int u, v, d,ok;
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d%d", &u, &v, &d, &ok);
            edge[i].from = u;
            edge[i].to = v;
            if(!ok)
                edge[i].value = d;
            else
                edge[i].value = 0;
        }
        sort(edge, edge + m, cmp);

        int res = 0;
        for(int i = 0; i < m; i++) {
            int u = find(edge[i].from);
            int v = find(edge[i].to);
            int cost = edge[i].value;
            if(u == v)
                continue;
            fa[u] = v;
            res += cost;
        }
        printf("%d\n", res);
    }
    return 0;
}
