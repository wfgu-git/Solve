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

int cow, car, how;
int door;
double solve(int cow, int car, int how)
{
    int door = cow + car;
    int t1,t2;
    t1 = door, t2 = door - how - 1;
    return (1.0*car/t1)*((car-1)*1.0/t2) + (1.0*cow/t1)*(1.0*car/t2);

}
int main(void)
{
    while(~sc3(cow, car, how)){
        printf("%.5lf\n",solve(cow,car,how)); 
    }
    return 0;
}
