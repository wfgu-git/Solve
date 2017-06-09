#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105;
char s[maxn];
int dp[maxn][maxn];
int cut[maxn][maxn];
void print_ret(int st, int ed)
{
    if (st > ed) return;

    if (st == ed) {
        if (s[st] == '(' || s[st] == ')')
            printf("()");
        else
            printf("[]");
    } else if (cut[st][ed] == -1) {
        putchar(s[st]);
        print_ret(st + 1, ed - 1);
        putchar(s[ed]);
    } else {
        print_ret(st, cut[st][ed]);
        print_ret(cut[st][ed] + 1, ed);
    }
}

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        //(dp[i + 1][i] = 0;
    }

    for (int len = 1; len < n; len++) {
    for (int i = 0; i + len < n; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']')) {
                dp[i][j] = dp[i + 1][j - 1];
                cut[i][j] = -1;
            }
            for (int k = i; k < j; k++) {
                if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j];
                    cut[i][j] = k;
                }
            }
        }
    }
    print_ret(0, n - 1);
    puts("");
    return 0;
}

