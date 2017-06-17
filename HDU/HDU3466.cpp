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

int dp[5010];
struct Item{
    int q,c,w;
}item[550];
bool cmp(Item a, Item b) {
    return a.q-a.c<b.q-b.c;
}
int n,v;
int main()
{
    while(cin>>n>>v){
        MEM(item,0);
        for(int i=1;i<=n;i++){
            cin>>item[i].c>>item[i].q>>item[i].w;
        } 
        sort(item+1,item+1+n,cmp);
        MEM(dp,0);
        for(int i=1;i<=n;i++){
            for(int j=v;j>=0;j--){
                if(item[i].c<=j&&item[i].q<=j)
                    dp[j]=max(dp[j],dp[j-item[i].c]+item[i].w);
            }
        }
        cout<<dp[v]<<endl;
    } 
    return 0;
}
