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

const int maxn = 105;
int dp[maxn][maxn];
// dp(i,j)  means the max cnt of the () from i to j
// dp(i,j) = max{dp(i+1,j-1)+1}

int check(char l, char r)
{
    if(l == '(' && r == ')')  return 1;
    if(l == '[' && r == ']')  return 1;
    return 0;
}

int main()
{
    string line;
    while(getline(cin, line) && line != "end") {
        memset(dp, 0, sizeof(dp));

        //do dp
        int n = line.size();
        for(int len = 0; len < n; len++) {
            for(int i = 0; i + len < n; i++) {
                int j = i + len;
                if(check(line[i], line[j]))  dp[i][j] = dp[i + 1][j - 1] + 1; // easy to understand
                for(int k = i; k < j; k++) { // enum
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        cout << dp[0][n - 1] * 2 << endl;
    }
    return 0;
}
