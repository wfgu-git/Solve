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
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
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

const int maxn = 10010;
int dfn[maxn], low[maxn], sccno[maxn];
int dfs_clock, sccno_cnt;
vector<int> G[maxn];
stack<int> s;

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfs_clock;
	s.push(u);
	for(int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i];
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(!sccno[u]) {
			low[u] = min(low[u], dfn[v]);
		}
	}

	if(dfn[u] == low[u]) {
		++sccno_cnt;
		while(true) {
			int x = s.top(); s.pop();
			sccno[x] = sccno_cnt;
			if(x == u)  break;
		}
	}
}

void find_sccno(int n)
{
	dfs_clock = sccno_cnt = 0;
	mset(low, 0), mset(dfn, 0), mset(sccno, 0);
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
}

//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n, m;
	while(~sc2(n, m)&&(m+n)) {
		for(int i=0;i<=n;i++)  G[i].clear();
		int u, v;
		while(m--) {
			sc2(u, v);
			G[u].pb(v);
		}
		find_sccno(n);
		if(sccno_cnt != 1)  printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
