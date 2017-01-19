//a native acmer
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
#include<climits>
#include<utility>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-8;
ll asked_max,asked_min,asked_Sergei;
ll seat[110][110];
int main(void)
{
    int n,m,x,y;
    ll k;
    mset(seat,0);
    scanf("%d%d%lld%d%d",&n,&m,&k,&x,&y);
    ll stu_num=n*m;
    ll asked_avg=k/stu_num;

    while(stu_num--)   k-=asked_avg;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            seat[i][j]=asked_avg;
        }
    }

    if(asked_avg%2==0){
        for(int i=1;i<=n;i++){
            if(!k) break;
            for(int j=1;j<=m;j++){
                if(k>0){
                   ++seat[i][j],--k;
                }
            }
        }
    }
    else{
        for(int i=n;i>=1;i--){
            if(!k) break;
            for(int j=1;j<=m;j++){
                if(k>0){
                   ++seat[i][j],--k;
                }
            }
        }
    }

    asked_Sergei=seat[x][y];
    asked_max=max(seat[1][1],seat[n][1]);
    asked_min=asked_max;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(seat[i][j]<asked_min){
                asked_min=seat[i][j];
                break;
            }
        }
    }

    printf("%lld %lld %lld\n",asked_max,asked_min,asked_Sergei);
    return 0;
}
