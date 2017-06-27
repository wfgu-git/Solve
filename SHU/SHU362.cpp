#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
const int inf = 0x3f3f3f3f;
int g[maxn + 2][maxn + 2];
int dp[maxn + 2][maxn + 2];
int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                dp[i][j] = -inf;
            }
        }

        for (int i = 0; i < m; i++) dp[0][i] = g[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = i; j < m; j++) {
                for (int k = 0; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + g[i][j]);
                }
            }
        }
        int ans = -inf;
        for (int i = 0; i < m; i++)
            ans = max(ans, dp[n - 1][i]);
        cout << ans << endl;
    }
    return 0;
}

