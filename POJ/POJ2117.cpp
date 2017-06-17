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
typedef long long ll;
// typedef __int64 ll;
typedef pair<int, int> PII;
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
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

const int maxn = 50050;
int dfn[maxn], low[maxn], bcc_cnt[maxn], fa[maxn];
int dfs_clock;
vector<int> G[maxn];

void init(int n)
{
	mset(dfn, 0), mset(low, 0), mset(fa, -1);
	for (int i = 0; i < n; i++) {
		G[i].clear();
		bcc_cnt[i] = 1;
	}
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfs_clock;
	int v;
	for (int i = 0; i < (int)G[u].size(); i++) {
		v = G[u][i];
		fa[v] = u;
		if (v != fa[v]) {
			if (!dfn[v]) {
				tarjan(v);
				low[u] = min(low[u], low[v]);
				if (dfn[u] <= low[v]) {
					++bcc_cnt[u];
				}
			} else if (low[u] > dfn[v]) {
				low[u] = dfn[v];
			}
		}
	}
}

int V, E;
int main(int argc, char const *argv[])
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while (sc2(V, E) == 2 && (V + E)) {
		init(V);
		int u, v;
		for (int i = 1; i <= E; i++) {
			sc2(u, v);
			G[u].pb(v);
			G[v].pb(u);
		}

		int cnt = 0;
		for (int i = 0; i < V; i++) {
			if (!dfn[i]) {
				++cnt;
				bcc_cnt[i] = 0;
				fa[i] = -1;
				tarjan(i);
			}
		}

		int res = -1;
		for (int i = 0; i < V; i++) {
			res = max(res, cnt - 1 + bcc_cnt[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}

