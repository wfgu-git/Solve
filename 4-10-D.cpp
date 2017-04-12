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

const int maxn = 550;
struct Edge {
	int from, to, dist;
	Edge(int u, int v, int d): from(u), to(v), dist(d) {}
};

struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int dis[maxn];
	int p[maxn];

	void init(int n) {
		this->n = n;
		for(int i = 0; i < n; i++)  G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist) {
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s, int n) {
		priority_queue<PII, vector<PII>, greater<PII> >q;
		for(int i = 0; i < n; i++)  dis[i] = INF;
		dis[s] = 0;
		memset(done, 0, sizeof(done));
		q.push(make_pair(0, s));
		while(!q.empty()) {
			PII x = q.top(); q.pop();
			int u = x.second;
			if(done[u])  continue;
			done[u] = true;
			for(int i = 0; i < (int)G[u].size(); i++) {
				Edge &e = edges[G[u][i]];
				if(dis[e.to] > dis[u] + e.dist) {
					dis[e.to] = dis[u] + e.dist;
					p[e.to] = G[u][i];
					q.push(make_pair(dis[e.to], e.to));
				}
			}
		}

	}
};

int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		bool flag_in, flag_out;
		Dijkstra solve;
		solve.init(550);
		flag_in = flag_out = false;
		scanf("%d%d", &n, &m);
		int u, v, d;
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &d);
			if(u == 0)  flag_out = true;
			if(v == 0)  {v = 543; flag_in = true;}
			solve.AddEdge(u, v, d);
		}
		solve.dijkstra(0, 551);
		if(!flag_in || !flag_out)  cout << -1 << endl;
		else {
			int res = solve.dis[543];
			if(res == INF)  cout << -1 << endl;
			else cout << res << endl;
		}
	}
	return 0;
}
