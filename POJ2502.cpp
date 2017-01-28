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

const double inf = 1000000.0;
const int maxn = 210;
double dist[maxn][maxn];
struct Node
{
	int x, y;
	int group;
} node[maxn];
double dis(Node a, Node b) {
	return sqrt(((double)a.x - (double)b.x) * ((double)a.x - (double)b.x)
	            + ((double)a.y - (double)b.y) * ((double)a.y - (double)b.y));
}
double cost(double d, bool walk) {
	if (walk)
		return d / (10000.0 / 60.0);
	else
		return d / (40000.0 / 60.0);
}

void Floyd(int n)
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (i == k)  continue;
			for (int j = 0; j < n; j++) {
				if (i == j || k == j)  continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	//init
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			dist[i][j] = inf;
		}
		//dist[i][i] = 0;
	}

	//build
	bool walk = true;
	scanf("%d%d%d%d", &node[0].x, &node[0].y, &node[1].x, &node[1].y);
	dist[0][1] = dist[1][0] = cost(dis(node[0], node[1]), walk);
	int n = 2;
	int pre = -1;
	while (sc2(node[n].x, node[n].y) == 2) {
		if (pre != -1 && node[n].x != -1)
			dist[n - 1][n] = dist[n][n - 1] = cost(dis(node[n - 1], node[n]), !walk);
		pre = node[n].x;
		if (pre != -1)  n++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == inf)
				dist[i][j] = dist[j][i] = cost(dis(node[i], node[j]), walk);
		}
	}

	//Floyd
	Floyd(n);

	//output
	printf("%.0f\n", dist[0][1]);
	return 0;
}
