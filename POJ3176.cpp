#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[352][352];
int dp[352][352];
int main()
{
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++){
                cin >> a[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) dp[n][i] = a[n][i];

        for (int i = n - 1; i >= 0; i--){
            for (int j = 0; j < i; j++){
                dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        cout << dp[1][0] << endl;
    }
    return 0;
}

