#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
int a[15][100002];
ll dp[15][100002];
int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n) {
		memset(a, 0, sizeof(a));
		int t_max = -1;
		for (int i = 0; i < n; i++) {
			int x, t;
			scanf("%d%d", &x, &t);
			a[++x][t]++;
			t_max = max(t_max, t);
		}
		
		const int inf = 0x3f3f3f3f;
		for (int i = 0; i <= 12; i++) dp[i][0] = -inf;
		dp[4][0] = dp[5][0] = dp[6][0] = 0;
		for (int t = 1; t <= t_max; t++) {
			for (int i = 1; i <= 11; i++) {
				dp[i][t] = (ll)a[i][t] + max(dp[i][t - 1],
						max(dp[i - 1][t - 1], dp[i + 1][t - 1]));
			}
		}
		ll ans = -1;
		for (int i = 1; i <= 11; i++) 
			ans = max(ans, dp[i][t_max]);
		printf("%lld\n", ans);
	}
	return 0;
}
