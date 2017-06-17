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

const int maxn=1010;
int dp[maxn][35];
int a[maxn];
int b[maxn];
int c[maxn];
int w[maxn];
int t;
int main()
{
    cin>>t;
    while(t--){
        MEM(c,0);MEM(w,0);MEM(dp,0);
        int n,v,k;
        cin>>n>>v>>k;
        for(int i=1;i<=n;i++){cin>>w[i];}
        for(int i=1;i<=n;i++){cin>>c[i];}

        for(int i=1;i<=n;i++){
            for(int j=v;j>=c[i];j--){
                for(int l=1;l<=k;l++){
                    a[l]=dp[j][l];
                    b[l]=dp[j-c[i]][l]+w[i];
                }
                int res,res1,res2;
                res=res1=res2=1;
                a[k+1]=b[k+1]=-1;
                while(res<=k&&(res1<=k||res2<=k)){
                    if(a[res1]>b[res2])
                        dp[j][res]=a[res1++];
                    else
                        dp[j][res]=b[res2++];
                    if(dp[j][res-1]!=dp[j][res])
                        res++;
                }
            } 
        }
        cout<<dp[v][k]<<endl;
    }
    return 0;
}
