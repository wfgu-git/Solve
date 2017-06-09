#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 4010;
int dp[maxn];
int c[maxn];

int main()
{
    int V;
    cin >> V;
    for (int i = 1; i <= 3; i++)    cin >> c[i];
    for (int i = 1; i <= V; i++)    dp[i] = -INF;
    dp[0] = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= V; j++) {
            if (c[i] <= j)    dp[j] = max(dp[j], dp[j - c[i]] + 1);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
