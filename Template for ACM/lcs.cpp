#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];
int main()
{
	ios::sync_with_stdio(false);

	string a, b;
	while (cin >> a >> b){
		int n = (int)a.size();
		int m = (int)b.size();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (a[i] == b[j])
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
	    }
		cout << dp[n][m] << endl;
	}
	return 0;
}
