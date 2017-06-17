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

int t,v,n;
const int maxn=1010;
int dp[1010];
int c[maxn];
int w[maxn];
int main()
{
    cin>>t;
    while(t--){
        MEM(c,0);MEM(w,0);
        cin>>v>>n;
        int l=1;
        int num,cost,weigth;
        while(n--){
            cin>>cost>>weigth>>num;
            while(num--){
                c[l]=cost;
                w[l]=weigth;
                l++;
            }
        }
        
        MEM(dp,0);
        for(int i=1;i<=l;i++){
            for(int j=v;j>=0;j--){
                if(c[i]<=j)
                    dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
            }
        }
        cout<<dp[v]<<endl; 
    }
    return 0;
}
