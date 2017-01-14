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
const int maxn=3550;
int w[maxn];
int c[maxn];
int dp[13000];
// 前i件物品在j大小的背包中的最大价值 

//int main()
//{
//    ios::sync_with_stdio(false);
//    int n,V;
//    cin>>n>>V;
//    for(int i=1;i<=n;i++){
//        cin>>c[i]>>w[i];
//    }
//    MEM(dp,0);
//    for(int i=1;i<=n;i++){
//        for(int j=V;j>=0;j--){
//            dp[i][j]=dp[i-1][j];
//            if(c[i]<=j){
//                dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
//            }    
//        }
//    }
//    cout<<dp[n][V]<<endl;
//    return 0;
//}

int main(void)
{
    ios::sync_with_stdio(false);
    int n,V;
    cin>>n>>V;
    MEM(dp,0);
    for(int i=1;i<=n;i++) { cin>>c[i]>>w[i]; }
    for(int i=1;i<=n;i++){
        cout<<i<<":\n";
        for(int j=V;j>=c[i];j--){
            if(c[i]<=j)
                dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
