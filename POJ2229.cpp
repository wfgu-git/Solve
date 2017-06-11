#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int moder = 1e9;
const int N = 1e6 + 2;
int dp[N];
void init()
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < N; i++) {
        if (i & 1)
            dp[i] = dp[i - 1];
        else
            dp[i] = (dp[i - 2] + dp[i / 2]) % moder;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    init();
    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}

