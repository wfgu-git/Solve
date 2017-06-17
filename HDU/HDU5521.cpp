#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;
// #define max(a,b)  ((a)>(b)?(a):(b))
// #define min(a,b)  ((a)<(b)?(a):(b))
typedef long long ll;
const ll INF = INT_MAX;
const int maxn = 2e5 + 50;
typedef pair<ll, int> PII;
struct Edge
{
	int from, to;
	ll dist;
	Edge(int u, int v, int d): from(u), to(v), dist(d) {}
};

struct Dijkstra
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	ll d[maxn];
	// int p[maxn];

	void init(int n) {
		this->n = n;
		for (int i = 0; i <= n; i++)  G[i].clear();
		for (int i = 0; i <= n; i++)  d[i] = INF;
		edges.clear();
	}

	void add_edge(int from, int to, int dist) {
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s) {
		priority_queue<PII, vector<PII>, greater<PII> > q;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		q.push(make_pair(0, s));

		while (!q.empty()) {
			PII x = q.top(); q.pop();
			int u = x.second;
			if (done[u])  continue;
			done[u] = true;
			for (int i = 0; i < (int)G[u].size(); i++) {
				Edge& e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					// p[e.to] = G[u][i];
					q.push(make_pair(d[e.to], e.to));
				}
			}
		}
	}
};

int main(int argc, char const * argv[])
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T, n, m, kase = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		Dijkstra Bessie, Elsie;
		Bessie.init(n + m);
		Elsie.init(n + m);
		for (int i = 1; i <= m; i++) {
			int k, d;
			scanf("%lld%d", &d, &k);
			for (int j = 0; j < k; j++) {
				int v;
				scanf("%d", &v);
				Bessie.add_edge(v, n + i, d);
				Bessie.add_edge(n + i, v, 0);
				Elsie.add_edge(v, n + i, d);
				Elsie.add_edge(n + i, v, 0);
			}
		}

		Bessie.dijkstra(1);
		Elsie.dijkstra(n);
		// printf("Debug\n");
		// for(int i=1;i<=n;i++){
		// 	if(i==1)  printf("Bessie: \n");
		// 	printf("%d  ", Bessie.d[i]);
		// }
		// printf("\n");
		// for(int i=1;i<=n;i++){
		// 	if(i==1)  printf("Elsie: \n");
		// 	printf("%d  ", Elsie.d[i]);
		// }
		// printf("\n");
		ll res = INF;
		for (int i = 1; i <= n; i++)  res = min(res, max(Bessie.d[i], Elsie.d[i]));
		if (res == INF) {
			printf("Case #%d: Evil John\n", ++kase);
			continue;
		}

		bool flag = false;
		printf("Case #%d: %lld\n", ++kase, res);
		for (int i = 1; i <= n; i++) {
			if (max(Bessie.d[i], Elsie.d[i]) == res) {
				if (flag)  printf(" ");
				flag = true;
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}