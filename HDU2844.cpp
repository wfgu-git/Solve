#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int a[maxn], cnt[maxn];
int dp[100005];
int main()
{
    int n, m;
    while (scanf ("%d%d", &n, &m) == 2 && (n + m)) {
        for (int i = 1; i <= n; i++) { scanf ("%d", &a[i]); }
        for (int i = 1; i <= n; i++) { scanf ("%d", &cnt[i]); }
        memset (dp, 0, sizeof (dp));
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] * a[i] >= m) {
                for (int v = 0; v <= m; v++) {
                    if (v >= a[i])
                        dp[v] |= dp[v - a[i]] & 1;
                }
            } else {
                int amount = cnt[i];
                int k = 1;
                while (k < amount) {
                    int cost = k * a[i];
                    for (int v = m ; v >= 0; v--) {
                        if (v >= cost)
                            dp[v] |= dp[v - cost] & 1;
                    }
                    amount -= k;
                    k <<= 1;
                }
                for (int v = m; v >= 0; v--) {
                    if (v >= amount * a[i])
                        dp[v] |= dp[v - amount * a[i]];
                }
            }
        }
        int ret = 0;
        for (int i = 1 ; i <= m; i++) if (dp[i]) ret++; // cout << "dp " << i << " is ok!" << endl;
        printf ("%d\n", ret);
    }
    return 0;
}

