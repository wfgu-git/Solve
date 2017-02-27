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
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pt(a) printf("%d\n",a)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn=55;
ll f[maxn];
int main(void)
{
    int n;
    //init
    f[1]=2,f[2]=3;
    for(int i=3;i<=50;i++){
        f[i] = f[i-1] + f[i-2];
    }
    while(~sc(n)){
        printf("%lld\n",f[n]); 
    }
    return 0;
}
