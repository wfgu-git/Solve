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
typedef long long ll;
//typedef __int64 i64;
typedef unsigned long long ull;
typedef priority_queue<int, vector<int>, greater<int> > pq_int;
typedef priority_queue<PII, vector<PII>, greater<PII> > pq_PII;
#define iscanf(a) scanf("%d",&a)
#define iscanf2(a,b) scanf("%d%d",&a,&b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
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
// const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

const double INF = 100000000.0;
const int maxn = 220;
int Head[maxn], Next[maxn];
struct Node {
	double x, y;
} stone[1010];
double G[maxn][maxn];
struct Edge {
	int u, v;
	double cost;
	Edge() {}
	Edge(int _u, int _v, double _cost): u(_u), v(_v), cost(_cost) {}
} e[1000010];

double getDis(Node a, Node b)
{
	return (double)sqrt((1.0 * a.x - b.x) * (1.0 * a.x - b.x) + (1.0 * a.y - b.y) * (1.0 * a.y - b.y));
}

void init()
{
	mset(stone, 0);
	mset(Head, -1);
	mset(Next, -1);
	mset(e, 0);
}

bool done[maxn];
double dist[maxn];
void Dijkstra(int start, int n)
{
	for(int i = 1; i <= n; i++)  done[i] = false;
	for(int i = 1; i <= n; i++)  dist[i] = INF;
	dist[start] = 0;

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > q;
	q.push(make_pair(0, start));
	while(!q.empty()) {
		PII cur = q.top(); q.pop();
		int u = cur.se;
		if(done[u])  continue;
		done[u] = true;
		if(done[2])  return;
		for(int i = Head[u]; i != -1; i = Next[i]) {
			int v = e[i].v;
			double d = e[i].cost;
			double max = Max(dist[u], d);
			// 每次都找的是这一条路径上最长的那一段
			/*
			for(int i=0;i<=n;i++){
				double max = Max(dist[u], G[u][i]);
				dist[v] = ()
			}
			*/
			dist[v] = Min(dist[v], max);
			q.push(make_pair(dist[v], v));
		}
	}
}

int main(int argc, char const *argv[])
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int stoneNum;
	int kase = 0;
	while(~scanf("%d", &stoneNum) && stoneNum) {
		if(kase)  printf("\n");
		printf("Scenario #%d\n", ++kase);
		init();
		for(int i = 1; i <= stoneNum; i++) {
			scanf("%lf%lf", &stone[i].x, &stone[i].y);
		}
		int edgeNum = 0;
		for(int i = 1; i <= stoneNum; i++) {
			int u = i;
			for(int j = 1; j <= stoneNum; j++) {
				if(i == j)  continue;
				int v = j;
				double d = getDis(stone[i], stone[j]);
				e[edgeNum].u = u;
				e[edgeNum].v = v;
				e[edgeNum].cost = d;
				Next[edgeNum] = Head[u];
				Head[u] = edgeNum++;
			}
		}

		Dijkstra(1, stoneNum);
		printf("Frog Distance = %.3f\n", dist[2]);
	}
	return 0;
}

