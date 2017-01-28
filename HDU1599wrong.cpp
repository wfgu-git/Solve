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
#define mp(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 110;
int N, M;
int dist[maxn][maxn];

void init()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
		}
	}
}

void Floyd()
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (i == k)  continue;
			for (int j = 1; j <= N; j++) {
				if (i == j || j == k)  continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	sc2(N, M);
	init();
	for (int i = 0; i < M; i++) {
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);
		dist[u][v] = cost;
	}
	Floyd();
	int mincost = INF;
	for (int i = 1; i <= N; i++) {
		mincost = min(mincost, dist[i][i]);
	}
	if (mincost == INF)  printf("It's impossible.\n");
	else printf("%d\n", mincost);
	return 0;
}
