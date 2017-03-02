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
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 55;

vector<int> G[maxn];
int color[maxn];
int n, m;
bool dfs(int u, int c)
{
	color[u] = c;
	for(int i = 0; i < (int)G[u].size(); i++) {
		if(color[G[u][i]] == c)  return false;
		if(color[G[u][i]] == 0 && !dfs(G[u][i], -c))  return false;
	}
	return true;
}


//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	while(~sc2(n, m)) {
		mset(color, 0);
		for(int i = 0; i <= n; i++) G[i].clear();
		for(int i = 0; i < m; i++) {
			int from, to;
			sc2(from, to);
			G[from].pb(to);
			G[to].pb(from);
		}

		for(int i = 1; i <= n; i++) {
			if(color[i] == 0) {
				if(!dfs(i, 1)) {
					printf("No\n");
					return 0;
				}
			}
		}
		printf("Yes\n"); 
	}
	return 0;
}
