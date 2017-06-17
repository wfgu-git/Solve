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
#define MP(a,b) (a,
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn=4010;
int kase;
ll dp[maxn][3];
int w[maxn];
int c[maxn];
int cost;
int main()
{
    int t;
    cin>>t;
    while(t--){ 
        MEM(c,0);MEM(w,0);MEM(dp,0);
        int n,V;
        cin>>n>>V;
        V*=2; 
        for(int i=1;i<=n;i++){
            cin>>c[i]>>w[i];
        }

        ll ans=-INF;
        for(int i=1;i<=n;i++) {
            ans=max(ans,(ll)w[i]);
        }

        for(int i=1;i<=n;i++){
            for(int j=V;j>=c[i];j--){
                for(int k=0;k<3;k++){
                    if(c[i]*2<=j)
                        //放在中间
                        dp[j][k]=max(dp[j][k],dp[j-c[i]*2][k]+w[i]);
                    if(k)
                        //放在两边
                        dp[j][k]=max(dp[j][k],dp[j-c[i]][k-1]+w[i]);
                    ans=max(ans,dp[j][k]);
                }
            }
        }
        cout<<"Case #"<<++kase<<": ";
        cout<<ans<<endl;

    }
    return 0;
}
