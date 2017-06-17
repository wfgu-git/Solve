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
const int maxn=10005;
int dp[maxn];
int c[]={0,150,200,350};
int main()
{
    int t,V;
    cin>>t;
    while(t--){
        MEM(dp,0);
        cin>>V;
        for(int i=1;i<=3;i++){
            for(int j=0;j<=V;j++){
                if(c[i]<=j)  dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
            }
        }
        cout<<V-dp[V]<<endl;
    }
    return 0;
}
