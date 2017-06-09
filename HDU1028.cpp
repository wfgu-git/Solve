#include <bits/stdc++.h>
using namespace std;

int dp[122][122];
int solve(int i, int j)
{
	if (dp[i][j] != -1) return dp[i][j];

	int ret;		
	if (i == 1 || j== 1) {
		ret = 1;
	} else if (i == j) {
		ret = 1 + solve(i, j - 1);
	} else if (i < j) {
		ret = solve(i, i);
	} else if (i > j){
		ret = solve(i - j, j) + solve(i, j - 1);
	}
	return dp[i][j] = ret;
}
int main()
{
	ios::sync_with_stdio(false);
	
	memset(dp, -1, sizeof(dp));
	int n;
	while (cin >> n){
		cout << solve(n, n) << endl;
	}
	return 0;
}

