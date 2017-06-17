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
int t[maxn];   //t[i] time of i-th book
int f[maxn];   //f[i] time of 1 2 3 ...i-th book

int main()
{
    ios::sync_with_stdio(false);
    int k,m;
    int kase=0;
    while(cin>>m>>k){
        MEM(dp,0),MEM(t,0),MEM(f,0);
        for(int i=1;i<=m;i++)   {cin>>t[i];f[i]=f[i-1]+t[i];} 

        for(int i=1;i<=k;i++){   //人数
            for(int j=i;j<=m;j++){//前i个人至少抄到i本(每个人都有书抄?)
                if(i==1)  dp[i][j]=f[j];
                else {
                    dp[i][j]=INF; 
                    for(int p=i-1;p<=j-1;p++){ //枚举第i-1位抄写员结束的位置 起码从(i-1)th本开始 最多抄到(j-1)th本
                    dp[i][j]=min(dp[i][j],max(dp[i-1][p],f[j]-f[p]));  //时间是由抄写时间最长的那个人决定的
                    }
                }
            }
        }
        cout<<"Case "<<++kase<<": ";
        cout<<dp[k][m]<<endl;
    }
    return 0;
}
