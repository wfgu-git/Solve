#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100002;
int n, k;
int a[102], m[102];
int dp[maxn];
int main()
{
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        for (int i = 0; i < n; i++) { cin >> m[i]; }

        memset(dp, -1, sizeof(int) * (k + 2));
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[j] >=0) {
                    dp[j] = m[i];
                } else if (j < a[i] || dp[j - a[i]] <= 0) {
                    dp[j] = -1;
                } else {
                    dp[j] = dp[j - a[i]] - 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= k; i++){
            if (dp[i] >= 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

