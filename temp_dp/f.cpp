#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int dp[2][5002];
int main() {

    int n;
    string str;
    while (cin >> n) {
        cin >> str;
        string rev(str.rbegin(), str.rend());

        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (str[i] == rev[j]) 
                    dp[k][j] = dp[k ^ 1][j - 1] + 1;
                else
                    dp[k][j] = max(dp[k ^ 1][j], dp[k][j - 1]);
            }
            k ^= 1;
        }
        cout << n - dp[k ^ 1][n - 1] << endl;
    }
    return 0;
}