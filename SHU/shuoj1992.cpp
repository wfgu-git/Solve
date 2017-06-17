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
#define MP(a,b) make_pair(a,b)
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn=550;
int dp[maxn][maxn];
int t[maxn];
//dp[k][m]   k个人抄m本书的最少时间 
//t[i]  前i本书需要的时间

int main()
{
    ios::sync_with_stdio(false);
    int m,k;
    while(cin>>m>>k){
        MEM(dp,0);
        MEM(t,0);
        for(int i=1;i<=m;i++){
            cin>>t[i];
            t[i]+=t[i-1];
        }
        for(int i=1;i<=k;i++){
            dp[1][i]=t[i];
        }

    }
    return 0;
}
