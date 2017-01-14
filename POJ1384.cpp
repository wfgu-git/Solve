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
const int maxn=10000;
int dp[maxn];
int w[550];
int c[550];
int main()
{
    int t;
    cin>>t;
    while(t--){
        MEM(w,0);MEM(c,0);
        int V,E,F;
        cin>>E>>F;
        V=F-E;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>w[i]>>c[i];

        }
        for(int i=1;i<=V;i++)  dp[i]=INF;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=V;j++){
                if(c[i]<=j)
                dp[j]=min(dp[j],dp[j-c[i]]+w[i]);

            }

        }
        if(dp[V]==INF){
            cout<<"This is impossible.\n";
            continue;

        }
        cout<<"The minimum amount of money in the piggy-bank is ";
        cout<<dp[V]<<'.'<<endl;
    }
    return 0;
}
    

