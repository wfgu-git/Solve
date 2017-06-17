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

const int maxn=10010;
double dp[maxn];
int c[maxn];
double w[maxn];

int main()
{
    int v,n;
    while(cin>>v>>n&&(v+n)){
        MEM(c,0);MEM(w,0);
        for(int i=1;i<=n;i++){
            cin>>c[i]>>w[i];
        } 
        for(int i=0;i<=v;i++)  dp[i]=1;
        for(int i=1;i<=n;i++){
            for(int j=v;j>=0;j--){
                if(c[i]<=j){
                    dp[j]=min(dp[j],dp[j-c[i]]*(1-w[i]));
                }
            }
        } 
        cout<<fixed<<setprecision(1)<<(1-dp[v])*100<<'%'<<endl;
    }
    return 0;
}
