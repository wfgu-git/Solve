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
typedef pair<__int64, int> PII;
#define mp(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
const int mod = 1e9 + 7;
const __int64 INF = 10000000000;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 50050 << 1;
int w[maxn];
// struct Edge
// {
// 	int from, to, dist;
// 	Edge(int u, int v, int d): from(u), to(v), dist(d) {}
// };

struct Dijkstra
{
	int n, m;
	// vector<Edge> edges;
	// vector<int> G[maxn];
	int u[maxn], v[maxn];
	__int64 weight[maxn];
	int first[maxn], Next[maxn];
	bool done[maxn];
	__int64 d[maxn];
	// int p[maxn];

	void init(int n) {
		this->n = n;
		this->m = 1;
		for (int i = 0; i <= n; i++) {
			// G[i].clear();
			d[i] = INF;
			done[i] = false;
			first[i] = -1;
			Next[i] = -1;
		}
		// edges.clear();
	}

	void add_edge(int from, int to, int dist) {
		u[m] = from, v[m] = to, weight[m] = dist;
		Next[m] = first[u[m]];
		first[u[m]] = m;
		m++;
	}

	__int64 dijkstra(int s) {
		__int64 res = 0;
		int cnt = 0;
		priority_queue<PII, vector<PII>, greater<PII> >q;
		d[s] = 0;
		q.push(mp(0, s));

		while (!q.empty()) {
			PII x = q.top(); q.pop();
			int uu = x.se;
			if (done[uu])  continue;
			done[uu] = true;
			cnt++;
			res += (__int64)w[uu] * (__int64)d[uu];
			for (int k = first[uu]; k != -1; k = Next[k]) {
				// Edge& e = edges[G[u][i]];
				if (d[v[k]] > d[uu] + weight[k]) {
					d[v[k]] = d[uu] + weight[k];
					// p[v[k]] = k;
					q.push(mp(d[v[k]], v[k]));
				}
			}
		}
		for (int i = 1; i <= n; i++)
			if (d[i] == INF)
				return -1;

		return res;
	}
};

int T, V, E;
int main(int argc, char const * argv[])
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		Dijkstra Christmas_Tree;
		scanf("%d%d", &V, &E);
		for (int i = 1; i <= V; i++)  w[i] = 0;
		Christmas_Tree.init(V);
		for (int i = 1; i <= V; i++)  scanf("%d", &w[i]);
		int u, v, d;
		for (int i = 1; i <= E; i++) {
			scanf("%d%d%d", &u, &v, &d);
			Christmas_Tree.add_edge(u, v, d);
			Christmas_Tree.add_edge(v, u, d);
		}

		// cout << "Debug:\n";
		// for (int i = 1; i <= n; i++) {
		// 	cout << "the " << i << "-th edge" << "  u = " << Christmas_Tree.u[i]
		// 	     << "  v = " << Christmas_Tree.v[i]
		// 	     << "  w = " << Christmas_Tree.weight[i] << endl;;
		// }
		// cout << "the first[] and the Next[]\n";
		// for (int i = 1; i <= n; i++) {
		// 	int k = Christmas_Tree.first[i];
		// 	while (k != -1) {
		// 		printf("u = %d v = %d d = %d\n", Christmas_Tree.u[k], Christmas_Tree.v[k], Christmas_Tree.weight[k]);
		// 		k = Christmas_Tree.Next[k];
		// 	}
		// }

		if (V == 0 || V == 1) {
			printf("0\n");
			continue;
		}
		__int64 ans = Christmas_Tree.dijkstra(1);
		if (ans == -1) {
			printf("No Answer\n");
		} else {
			printf("%I64d\n", ans);
		}
	}
	return 0;
}

