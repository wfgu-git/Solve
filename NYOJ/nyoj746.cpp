#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

ll a[35][35];
ll dp[35][35];
// a[i][j]  the num i-th to j-th
// dp[i][j] means 0~i insert j '*' ---max{value}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        memset(a, 0, sizeof(a));
        string x;
        int m, n;
        cin >> x >> m;
        n = x.size();
        for(int i = 0; i < n; i++) {
            a[i][i] = x[i] - '0';
            for(int j = i + 1; j < n; j++) {
                a[i][j] = a[i][j - 1] * 10 + x[j] - '0';
            }
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)  dp[i][0] = a[0][i];

        for(int j = 1; j <= m; j++) { // enum the num of '*'
            for(int i = j; i < n; i++) {
                for(int k = 0; k < i; k++) {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] * a[k + 1][i]);
                }
            }
        }

        cout << dp[n - 1][m-1] << endl;
    }
    return 0;
}
