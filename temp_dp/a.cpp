#include <iostream>
#include <cstring>
using namespace std;

int dp[22][8005 * 2 + 1];
int p[22], w[22];
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= m; i++) cin >> w[i];

        const int delta = 8005;
        memset(dp, 0, sizeof(dp));
        dp[0][delta] = 1;

        for (int i = 1; i <= m; i++) {
            for (int v = 0; v <= 8005 * 2; v++) {
                if (dp[i - 1][v]) {
                    for (int j = 1; j <= n; j++) {
                        dp[i][v + w[i] * p[j]] += dp[i - 1][v];
                    }
                }
            }
        }
        cout << dp[m][delta] << endl;
    }
    return 0;
}
