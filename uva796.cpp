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
typedef priority_queue<int, vector<int>, greater<int> > pq_int;
typedef priority_queue<PII, vector<PII>, greater<PII> > pq_PII;
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
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn = 100010;
int dfn[maxn], low[maxn], dfs_clock;
// priority_queue<PII, vector<PII>, greater<PII> > q;
vector<int> G[maxn];
struct Bridge {
	int u, v;
	Bridge() {}
	Bridge(int _u, int _v): u(Min(_u, _v)), v(Max(_u, _v)) {}
	bool operator<(const Bridge &b) {
		if(u == b.u)  return v < b.v;
		return u < b.u;
	}
};
vector<Bridge> res;
void tarjan(int u, int pre) {
	dfn[u] = low[u] = ++dfs_clock;
	int sz = (int)G[u].size();
	for(int i = 0; i < sz; i++) {
		int v = G[u][i];
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(dfn[u] < low[v]) {
				res.push_back(Bridge(u, v));
			}
		} else if(pre != v) {
			low[u] = min(low[u], dfn[v]);

		}
	}
}

void init(int n) {
	dfs_clock = 0;
	res.clear();
	for(int i = 0; i <= n; i++)  G[i].clear();
	mset(dfn, 0);
	mset(low, 0);
}

int main(int argc, char const *argv[]) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n;
	// int kase = 0;
	while(~scanf("%d", &n)) {
		// if(kase++)  printf("\n");
		init(n);
		//build
		int u, v, k;
		for(int i = 0; i < n; i++) {
			scanf("%d (%d) ", &u, &k);
			// cout << u << " " << k_str;
			for(int j = 0; j < k; j++) {
				scanf("%d", &v);
				// cout << v << " ";
				G[u].pb(v);
				G[v].pb(u);
			}
			// cout << endl;
		}
		//tarjan
		for(int i = 0; i < n; i++) {
			if(!dfn[i]) {
				tarjan(i, -1);
			}
		}
		//print res

		int sz;
		printf("%d critical links\n", sz = res.size());
		sort(res.begin(), res.end());
		for(int i = 0; i < sz; i++) {
			printf("%d - %d\n", res[i].u, res[i].v);
		}
		printf("\n");
	}
	return 0;
}

