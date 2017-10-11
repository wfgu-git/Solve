/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

int n;
int dist[maxn][maxn];
int dp[1 << 16][maxn];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  freopen("/home/wfgu/solve/data.out", "w", stdout);
#endif
	int kase = 0;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &dist[i][j]);
				if (dist[i][j] < 0) dist[i][j] = inf;
			}
		}
		int ans = inf;
		for (int i = 0; i < (1 << n); ++i) {
			for (int j = 0; j < n; ++j) {
				dp[i][j] = inf;
			}
		}
		int m = (1 << n);
		dp[1][0] = 0;
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (i & (1 << j)) continue;
				if (!(i & 1)) continue;
				for (int k = 0; k < n; ++k) {
					if (i & (1 << k)) {
						dp[(1 << j) | i][j] = min(dp[(1 << j) | i][j], dp[i][k] + dist[k][j]);
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			ans = min(ans, dp[m - 1][i] + dist[i][0]);
		}

		printf("Case %d\n", ++kase);
		if (ans >= inf) {
			puts("No loop");
			continue;
		}
		printf("%d\n", ans);
	}
}
