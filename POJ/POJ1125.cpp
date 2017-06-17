#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


//这个题坑在题意
const int INF = 0x3f3f3f3f;
const int maxn = 110;
int dist[maxn][maxn];
//Dis(i,j) = min{Dis(i,j), Dis(i,k)+Dis(k,j)}
//dist[i][j]  the mincost from i to j
int n;

void init()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)  dist[i][j] = 0;
			else  dist[i][j] = INF;
		}
	}
}

void floyd()
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == i)  continue;
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k)  continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	while (cin >> n && n) {
		init();
		int N, v, d;
		for (int u = 1; u <= n; u++) {
			cin >> N;
			while (N--) {
				cin >> v >> d;
				dist[u][v] = d;
				dist[v][u]=d;
			}
		}
		floyd();
		int ans = 0x3f3f3f3f, last = 0;
		for (int i = 1; i <= n; i++) {
			int mincost = 0;
			for (int j = 1; j <= n; j++) {
				if (i == j)  continue;
				mincost = max(mincost, dist[i][j]);
			}
			if (mincost < ans) {
				ans = mincost;
				last = i;
			}
		}
		if (ans == INF)
			cout << "disjoint" << endl;
		else
			cout << last << " " << ans << endl;
	}
	return 0;
}