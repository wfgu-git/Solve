#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int w[1005];
int dp[1005][35][2];
int main() {
    int T, m;
    while (scanf("%d%d", &T, &m) == 2) {
        for (int i = 1; i <= T; i++) {
            scanf("%d", &w[i]);
            w[i]--;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= T; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k < 2; k++) {
                    if (k == w[i]) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + 1);
                        dp[i][j + 1][k ^ 1] = max(dp[i][j + 1][p ^ 1], dp[i - 1][j][k]);
                    } else {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                        dp[i][j + 1][k ^ 1] = max(dp[i][j + 1][k ^ 1], dp[i - 1][j][k] + 1);
                    }
                }
            }
        }
        int ans = *max_element(dp[T][0], dp[T][0] + (m + 1) * 2);
        printf("%d\n", ans);
    }
    return 0;
}
