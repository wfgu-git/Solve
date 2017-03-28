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

const int maxn = 20020;
int dfn[maxn], low[maxn], sccno[maxn];
int in[maxn], out[maxn];
int dfs_clock, sccno_cnt;
int Indeg, Outdeg;
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
		} else if(!sccno[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}

	if(low[u] == dfn[u]) {
		++sccno_cnt;
		while(true) {
			int x = s.top(); s.pop();
			sccno[x] = sccno_cnt;
			if(x == u)  break;
		}
	}
}

void find_scc(int n)
{
	mset(dfn, 0), mset(low, 0), mset(sccno, 0);
	mset(in, 0), mset(out, 0);
	dfs_clock = sccno_cnt = 0;
	Indeg = Outdeg = 0;
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}

	for(int u = 1; u <= n; u++) {
		for(int i = 0; i < (int)G[u].size(); i++) {
			int v = G[u][i];
			if(sccno[v] != sccno[u]) {
				out[sccno[u]]++;
				in[sccno[v]]++;
			}
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
	while(~sc2(n, m)) {
		for(int i = 0; i <= n; i++)  G[i].clear();
		while(!s.empty())  s.pop();
		int u, v;
		while(m--) {
			sc2(u, v);
			G[u].pb(v);
		}
		find_scc(n);
		for(int i = 1; i <= n; i++) {
			//printf("Debug:\nsccno[%d] = %d\n", i, sccno[i]);
		}
		//printf("sccno_cnt = %d\n", sccno_cnt);
		for(int i = 1; i <= sccno_cnt; i++) {
			if(in[i] == 0)  Indeg++;
			if(out[i] == 0)  Outdeg++;
			//printf("in[%d] = %d    out[%d] = %d\n", i, in[i], i, out[i]);
		}
		//printf("Indeg = %d  Outdeg = %d\n", Indeg, Outdeg);
		if(sccno_cnt == 1)  printf("0\n");
		else  printf("%d\n", max(Indeg, Outdeg));
	}
	return 0;
}

/*
3 5
1 2
3 1
1 3
2 3
2 1
*/