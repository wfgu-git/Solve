#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5;
int dp[maxn + 5];
int m[maxn + 5];
int c[maxn + 5];
int main() {
    ios::sync_with_stdio(false);
    int V, n;
    while (cin >> V >> n) {
        for (int i = 0; i < n; i++) {
            int num, w;
            cin >> num >> w;
            m[i] = num;
            c[i] = w;
        }
		memset(dp, -1, sizeof(dp));
  		dp[0] = 0;
  		for (int i = 0; i < n; i++) {
			for (int v = 0; v <= V; v++) {
				if (dp[v] >= 0) {
					dp[v] = m[i];	
				} else if (v < c[i] || dp[v - c[i]] <= 0) {
					dp[v] = -1;
				} else {
					dp[v] = dp[v - c[i]] - 1;
				}
			}
		}		
		int ans = -1;
		for (int i = 0; i <= V; i++) {
			if (dp[i] >= 0) {
				ans = max(ans, i);
			}
		}
		cout << ans << endl;
    }
}
