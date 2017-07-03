#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int a[maxn + 2];
int dp[maxn + 2], l[maxn + 2], r[maxn + 2];
int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        for_each(a, a + n, [](int &x) {scanf("%d", &x);});

        memset(dp, 0, sizeof(dp));
        dp[0] = -INT_MAX;
        int L, R, ans = -INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (dp[i - 1] < 0) {
                dp[i] = a[i - 1];
                l[i] = r[i] = i;
            } else {
                dp[i] = dp[i - 1] + a[i - 1];
                l[i] = l[i - 1];
                r[i] = i;
            }
            if (dp[i] > ans) {
                ans = dp[i];
                L = l[i];
                R = r[i];
            }
        }
        printf("Case %d:\n", cas);
        printf("%d %d %d\n", ans, L, R);
        if (cas < T)
            printf("\n");
    }
    return 0;
}

