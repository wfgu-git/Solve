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

const int maxn=110;
int dp[maxn][maxn];   //背包有两个容量  一个是耐久度-c[i] 一个是 杀怪数的上限 -1
int c[maxn];
int w[maxn];
int n,m,k,s;

int main()
{
    while(cin>>n>>m>>k>>s){
        int used=INF;
        MEM(dp,0);MEM(c,0);MEM(w,0);
        for(int i=1;i<=k;i++){
            cin>>w[i]>>c[i];
        }

        for(int i=1;i<=k;i++){
            for(int j=c[i];j<=m;j++){
                for(int l=1;l<=s;l++){
                    if(c[i]<=j&&l>0){
                        dp[j][l]=max(dp[j][l],dp[j-c[i]][l-1]+w[i]);
                        if(dp[j][l]>=n&&j<used){
                            used=j;            
                        }
                    }
                }
            }
        }
        if(used!=INF)
        cout<<m-used<<endl;
        else
        cout<<-1<<endl;
    }
    return 0;
}
