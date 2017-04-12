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

const int maxn = 50050;
int dfs_clock, sccno_cnt;
int dfn[maxn], low[maxn], sccno[maxn];
int in[maxn], pre[maxn], vis[maxn], belong[maxn];
vector<PII> G[maxn];
stack<int> s;
map<PII, int> id;

struct Edge {
	int u, v, w;
	void add_edge(int _u, int _v, int _w)
	{
		u = _u, v = _v, w = _w;
	}
} e[100010];

Edge edge[100010];

int ZL(int root, int V, int E)
{
	int res = 0;
	while(true) {
		for(int i = 0; i < V; i++) {
			in[i] = INF;
		}

		for(int i = 0; i < E; i++) {
			int u = edge[i].u, v = edge[i].v, w = edge[i].w;
			if(in[v] > w && u != v) {
				pre[v] = u;
				in[v] = w;
			}
		}

		int cntRing = 0;
		mset(vis, -1), mset(belong, -1);
		in[root] = 0;
		for(int i = 0; i < V; i++) {
			res += in[i];
			int v = i;
			while(vis[v] != i && belong[v] == -1 && v != root) {
				vis[v] = i;
				v = pre[v];
			}
			if(v != root && belong[v] == -1) {
				for(int u = pre[v]; u != v; u = pre[u]) {
					belong[u] = cntRing;
				}
				belong[v] = cntRing++;
			}
		}

		if(cntRing == 0)  break;
		for(int i = 0; i < V; i++) {
			if(belong[i] == -1) {
				belong[i] = cntRing++;
			}
		}


		for(int i = 0; i < E; i++) {
			int v = edge[i].v;
			edge[i].u = belong[edge[i].u];
			edge[i].v = belong[edge[i].v];
			if(edge[i].u != edge[i].v) {
				edge[i].w -= in[v];
			}
		}

		V = cntRing;
		root = belong[root];
	}
	return res;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfs_clock;
	s.push(u);
	for(int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i].fi;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(!sccno[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}

	if(dfn[u] == low[u]) {
		sccno_cnt++;
		while(true) {
			int x = s.top();
			s.pop();
			sccno[x] = sccno_cnt;
			if(x == u)  break;
		}
	}
}

void find_scc(int n)
{
	dfs_clock = sccno_cnt = 0;
	mset(dfn, 0), mset(low, 0), mset(sccno, 0);
	for(int i = 0; i < n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
}

int main(void)
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, m;
	while(scanf("%d%d", &n, &m) == 2) {
		id.clear();
		for(int i = 0; i <= n; i++)  G[i].clear();
		int u, v, w, edgeNum = 0;
		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			PII cur;
			cur = make_pair(u, v);
			if(!id.count(cur)) {
				G[u].push_back(make_pair(v, w));
				id[cur] = edgeNum;
				e[edgeNum++].add_edge(u, v, w);
			} else {
				e[id[cur]].w = min(e[id[cur]].w, w);
			}
		}

		find_scc(n);
		int E = 0;
		for(int i = 0; i < edgeNum; i++) {
			int from = e[i].u, to = e[i].v, cost = e[i].w;
			if(sccno[from] != sccno[to]) {
				int u = sccno[from] - 1, v = sccno[to] - 1;
				edge[E].u = u, edge[E].v = v, edge[E].w = cost;
				E++;
			}
		}
		printf("%d\n", ZL(sccno[0] - 1, sccno_cnt, E));
	}
	return 0;
}
