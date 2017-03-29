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
struct Edge {
	int u, v;
	double w;
	void add_edge(int _u, int _v, double _w) {
		u = _u, v = _v, w = _w;
	}
} edge[maxn];
double x[maxn], y[maxn];
double in[maxn];
int root, pre[maxn], vis[maxn], belong[maxn];

double getDis(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double ZL(int root, int V, int E) {
	double res = 0;
	while(true) {
		for(int i = 0; i < V; i++) {
			in[i] = INF;
		}

		for(int i = 0; i < E; i++) {
			int u = edge[i].u, v = edge[i].v;
			double w = edge[i].w;
			if(in[v] > w && u != v) {
				pre[v] = u;
				in[v] = w;
			}
		}
		for(int i = 0; i < V; i++) {
			if(in[i] == INF && i != root)  return -1;
		}


		int cntRing = 0;
		mset(belong, -1), mset(vis, -1);
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

int main(int argc, char const * argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
		}
		int edgeNum = 0;
		int from, to;
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &from, &to);
			--from, --to;
			if(from == to)  edge[edgeNum++].add_edge(from, to, INF);
			else  edge[edgeNum++].add_edge(from, to, getDis(from, to));
		}
		double res = ZL(0, n, m);
		if(res != -1) {
			printf("%.2f\n", res);
		} else {
			printf("poor snoopy\n");
		}
	}
	return 0;
}

