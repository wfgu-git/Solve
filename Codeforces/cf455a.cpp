#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
#include<climits>
#include<queue>
#include<utility>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pt(a) printf("%d\n",a)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 1e5+5;
ll dp[maxn][2];
ll cnt[maxn];

//  
// dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
// dp[i][1] = dp[i-1][0] + cnt[i] * i;
int main(void)
{
    int n;
    sc(n);
    mset(cnt,0),mset(dp,0);
    for(int i=1; i<=n; i++){
        ll temp;
        scanf("%lld", &temp);
        cnt[temp]++;
    }
    for(int i=1; i<=100010; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + (ll)cnt[i] * (ll)i;
    }
    printf("%lld\n", max(dp[100000][0], dp[100000][1]));
    return 0;
}
