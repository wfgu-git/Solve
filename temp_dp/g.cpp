#include <iostream>
#include <algorithm>
using namespace std;

int a[352][352];
int dp[352][352];
int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= i; j++) 
				cin >> a[i][j];	
		for (int i = 1; i <= n; i++) dp[n][i] = a[n][i];
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);	
			}
		}	
		cout << dp[1][1] << endl;
	}
	return 0;
}
