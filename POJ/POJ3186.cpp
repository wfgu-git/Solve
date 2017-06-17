//Life has never been fucking so easy...
//...Acm without girlfriend
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<functional>
#include<memory>
#include<utility>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cctype>
#include<cstdlib>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int maxn = 2020;
int a[maxn];
int dp[maxn][maxn];
// dp(i,j)  --> the best value of (i,j)
// dp(i,j) = max{dp[i+1][j]+a[i]*(n-len+1) ,dp[i][j-1] + a[j]*(n-len+1)}
int main(void)
{
    ios::sync_with_stdio(false);
//    cin.tie(nullptr);

    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; i++)  cin >> a[i];
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            dp[i][i] = a[i] * n;
        }
        for(int len = 1; len < n; len++) {
            for(int i = 1; i <= n && i + len <= n; i++) {
                int j = i + len;
                for(int k = i; k < j; k++) {
                    //cout << "debug dp(i,j) " << i << " " << j << " " << dp[i][j] << endl;
                    dp[i][j] = max(dp[i + 1][j] + a[i] * (n - len), dp[i][j - 1] + a[j] * (n - len));
                    //cout << "debug dp(i,j) " << i << " " << j << " " << dp[i][j] << endl;
                }
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}
