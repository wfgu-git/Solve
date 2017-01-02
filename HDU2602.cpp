#include<bits/stdc++.h>

using namespace std;

const int maxn=1000+5;
int V[maxn];
int W[maxn];
int dp[maxn][maxn];

int main(void)
{
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,C;
        cin>>n>>C;
        for(int i=1;i<=n;i++)
            cin>>W[i];  //价值/重量
        for(int i=1;i<=n;i++)
            cin>>V[i];  //体积
        for(int i=1;i<=n;i++)
            for(int j=C;j>=0;j--){
                dp[i][j]=(i==1?0:dp[i-1][j]);
                if(j>=V[i])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-V[i]]+W[i]);
        }
        cout<<dp[n][C]<<endl;
    }
    return 0;
}
