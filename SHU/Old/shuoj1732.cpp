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
int v[maxn];//value
int w[maxn];//weigth
int dp[maxn];//dp[i] 剩余容量为i时背包的最大价值

int main()
{
    ios::sync_with_stdio(false);
    int n,W;
    int kase=0;
    while(cin>>n>>W){
        MEM(v,0);MEM(w,0);MEM(dp,0);
        for(int i=1;i<=n;i++)    {cin>>v[i];}
        for(int i=1;i<=n;i++)    {cin>>w[i];}

        
        for(int i=1;i<=n;i++){
            for(int j=W;j>=0;j--){
                if(j>=w[i])
                    dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout<<"Case "<<++kase<<":"<<dp[W]<<endl;


    }
    return 0;
}
