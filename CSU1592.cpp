/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <cctype>
#include <climits>
#include <utility>
#include <memory>
#include <functional>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
//typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a,b) scanf("%d%d",&a, &b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a, &b, &c)
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) sort(all(x)); v.erase(unique(all(v)), end())
#define mp(a,b) make_pair(a,b)
#define clr(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

//gcd lcm
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

const int maxn = 105;
int a[maxn];
int dp[maxn][maxn];
int sum[maxn][maxn];
int main(int argc, char const *argv[]) {
// freopen("data.in","r",stdin);
// freopen("data.out","w",stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        clr(a, 0), clr(dp, 0x3f), clr(sum, 0);
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            dp[i][i] = 0;
            sum[i][i] = a[i];
        }

        // dp in Interval
        // dp(i,j)  the max value of (i,j)
        for(int len = 1; len <= n; len++) { // enum len
            // if(len != 1) printf("\n\n");
            // printf("Length ==> %d\n" , len);
            for(int i = 1; i <= n && i + len <= n; i++) { // enmu the start
                int j = i + len;
                for(int k = i; k < j; k++) {
                    sum[i][j] = sum[i][k] + sum[k + 1][j];
                    // printf("sum[%d][%d](%d) = sum[%d][%d](%d) + sum[%d][%d](%d) \n", i, j, sum[i][j], i, k, sum[i][k], k + 1, j, sum[k + 1][j]);
                    if(dp[i][j] > dp[i][k] + dp[k + 1][j] + sum[i][j]) {
                        // printf("Before \ndp[%d][%d] = %d\n", i, j, dp[i][j]);
                        dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[i][j];
                        // printf("After \ndp[%d][%d] = %d == dp[%d][%d] + dp[%d][%d] + sum[%d][%d]\n", i, j, dp[i][j],i,k,k+1,j,i,j);
                    }
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}

