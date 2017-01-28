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

const int maxn = 1010;
int n, m;
int dist[maxn][maxn];

void init()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
}


int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	//input
	sc2(n, m);
	init();
	int u, v, d;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &d);
		if (dist[u][v] > d)
			dist[u][v] = d, dist[v][u] = d;
	}

	//Floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k)  continue;
			for (int j = 1; j <= n; j++) {
				if (i == j || k == j)  continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	//print
	for (int i = 1; i <= n; i++) {
		if (i != 1)  printf("\n");
		for (int j = 1; j <= n; j++) {
			if (j != 1)  printf(" ");
			printf("%d", dist[i][j]);
		}
	}
	printf("\n");
	return 0;
}
