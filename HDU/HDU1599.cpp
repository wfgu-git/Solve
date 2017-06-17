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
#define INF 0xFFFFFFF
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 110;
int N, M, ret;
int dist[maxn][maxn];
int grid[maxn][maxn];
void init() {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			dist[i][j] = INF;
			grid[i][j] = INF;
		}
		grid[i][i] = dist[i][i] = 0;
	}
}

void Floyd() {
	ret = INF;
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i < k; i++) {
			for(int j = i + 1; j < k; j++) {
				ret = min(ret, dist[i][j] + grid[i][k] + grid[k][j]);
			}
		}

		for(int i = 1; i <= N; i++) {
			// if(i == k)  continue;
			for(int j = 1; j <= N; j++) {
				// if(i == j || j == k)  continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while(scanf("%d%d", &N, &M) != EOF) {
		init();
		for(int i = 0; i < M; i++) {
			int u, v, cost;
			scanf("%d%d%d", &u, &v, &cost);
			if(dist[u][v] > cost) {
				dist[u][v] = dist[v][u] = cost;
				grid[u][v] = grid[v][u] = cost;
			}
		}

		Floyd();
		if(ret == INF)
			printf("It's impossible.\n");
		else
			printf("%d\n", ret);
	}
	return 0;
}

