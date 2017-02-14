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
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn=100000;
int sum[maxn<<2];
int lazy[maxn<<2];

void PushUp(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int l,int r,int rt)
{
    if(lazy[rt]==-1){
        return ;
    }
    lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    int m=(l+r>>1);
    sum[rt<<1]+=lazy[rt]*(m-l+1);
    sum[rt<<1|1]+=lazy[rt]*(r-m);
    lazy[rt]=-1;
}

void build(int l,int r,int rt)
{
    lazy[rt] = -1;
    if(l==r){
        sum[rt]=0;
        return ;
    }   
    int m=(l+r)>>1;
    build(lch);
    build(rch);
    PushUp(rt);
}

void update(int L,int R,int k,int l,int r,int rt)
{
    if(L<=l&&r<=R){
        lazy[rt]=k;
        sum[rt]+=lazy[rt]*(r-l+1);
    }else{
        PushDown(l, r, rt);
        int m = l + (r-l) / 2;
        if(L <= m)  update(L,R,k,lch);
        if(m < R)  update(L,R,k,rch);
        PushUp(rt);
    }
}

int query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R){
        return sum[rt];
    }
    PushDown(l,r,rt);
    int m=(l+r)>>1;
    
}

int main(void)
{
        
    return 0;
}
