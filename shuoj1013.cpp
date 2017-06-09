#include <bits/stdc++.h>
using namespace std;

long long dp[25][25];
int _dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int _dy[] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
inline void init(const int &x, const int &y)
{
    for(int i = 0; i < 9; i++){
        int tx = x + _dx[i];
        int ty = y + _dy[i];
        if(tx >= 0 && ty >= 0){
            dp[tx][ty] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m, x, y;
    while(cin >> n >> m >> x >> y){
        //fill(begin(dp), end(dp), 1);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j] = 1;
            }
        }
        init(x, y);
        for(int r = 0; r <= n; r++){
            for(int c = 0; c <= m; c++){
                if(dp[r][c] == 0) continue;
                if(r == 0 && c == 0) continue;
                else if(r == 0) dp[r][c] = dp[r][c - 1];
                else if(c == 0) dp[r][c] = dp[r - 1][c];
                else dp[r][c] = dp[r][c - 1] + dp[r - 1][c];
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}

