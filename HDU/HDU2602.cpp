#include<bits/stdc++.h>

using namespace std;
#define MEM(x,i) memset(x,i,sizeof(x))
const int maxn=1000+5;
int c[maxn];
int v[maxn];
int dp[maxn];

//int main(void)
//{
////    freopen("data.in","r",stdin);
////    freopen("data.out","w",stdout);
//    int T;
//    cin>>T;
//    while(T--)
//    {
//        int n,C;
//        cin>>n>>C;
//        for(int i=1;i<=n;i++)
//            cin>>W[i];  //价值/重量
//        for(int i=1;i<=n;i++)
//            cin>>V[i];  //体积
//        for(int i=1;i<=n;i++)
//            for(int j=C;j>=0;j--){
//                dp[i][j]=(i==1?0:dp[i-1][j]);
//                if(j>=V[i])
//                    dp[i][j]=max(dp[i][j],dp[i-1][j-V[i]]+W[i]);
//        }
//        cout<<dp[n][C]<<endl;
//    }
//    return 0;
//}

int main(void)
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        MEM(v,0),MEM(c,0),MEM(dp,0);
        int n,V;
        cin>>n>>V;
        for(int i=1;i<=n;i++)    cin>>v[i];
        for(int i=1;i<=n;i++)    cin>>c[i];

        for(int i=1;i<=n;i++){
            for(int j=V;j>=0;j--){
                if(c[i]<=j)
                    dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
            }
        }

        cout<<dp[V]<<endl;
    }
    return 0;
}
