#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int moder = 10000007;
const int maxn = 1e6;
ll dp[maxn + 2][2];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 1;
		dp[1][1] = 1;
		for (int i = 1; i + 1 <= n; i++) {
			dp[i + 1][0] = dp[i][0] + dp[i][1];
			dp[i + 1][1] = dp[i][0];
		}
		ll ans =  1;
		ll base = (dp[n][0] + dp[n][1]) % moder;
		for (int i = 0; i < 3; i++) {
			ans = ans * base % moder;	
		}	
		cout << ans << endl;
	}
	return 0;
}
