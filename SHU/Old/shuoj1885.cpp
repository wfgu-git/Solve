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
#define pr(a) printf("%d\n",a)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn=1e5;
int a[maxn];
int bit[maxn];
int n,m;
int lowbit(int x)
{
    return x & (-x);
}

void add(int idx, int k)
{
    for(int i=idx; i>0; i-=lowbit(i)){
        bit[i] += k;
    }
}

int query(int idx)
{
    int res = 0;
    while(idx <= n){
        res += bit[idx];
        idx += idx & -idx;
    }
    return res;
}

int main(void)
{
    sc2(n,m);
    for(int i=1;i<=n;i++){
        sc(a[i]);
    }

    while(m--){
        int flag;
        sc(flag);
        if(flag == 1){
            int l,r,k;
            sc3(l,r,k);
            add(r,k);
            add(l-1,-k);
            continue;
        }
        else if(flag == 2){
            int index;
            sc(index);
            int ans=a[index]+query(index);
            pr(ans);
            continue;
        }
    }
    return 0;
}
