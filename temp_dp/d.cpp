#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1002];
int dp[1002];
int main()
{
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j]) 
					dp[i] = max(dp[i], dp[j] + 1);	
			}
		}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
