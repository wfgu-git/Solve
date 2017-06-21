#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 3500;
int c[maxn], w[maxn];
int dp[13000];
int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> c[i] >> w[i]; 
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int v = m; v >= 0; v--) {
                if (v >= c[i]) 
                    dp[v] = max(dp[v], dp[v - c[i]] + w[i]);
            } 
        }
        cout << dp[m] << endl;
    }
    return 0;
}