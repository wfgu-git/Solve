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
struct Segtree{
    int sum,lazy;
}st[maxn<<2];

void PushUp(int rt)
{
    st[rt].sum = (st[rt<<1].sum > st[rt<<1|1].sum)?st[rt<<1].sum:st[rt<<1|1].sum;
}

void PushDown(int l, int r, int rt)
{
    if(st[rt].lazy != 0){
    st[rt<<1].lazy += st[rt].lazy;
    st[rt<<1|1].lazy += st[rt].lazy;
    st[rt<<1].sum += st[rt].lazy;
    st[rt<<1|1].sum += st[rt].lazy;
    st[rt].lazy = 0;
    }
}

void build(int l, int r, int rt)
{
    st[rt].lazy=0;
    if(l==r){
        st[rt].sum=0;
        return ;
    }
    int m=(l+r)>>1;
    build(lch);
    build(rch);
    PushUp(rt);
}

void update(int L, int R, int k, int l, int r, int rt)
{
    if(L <= l && r <= R){
        st[rt].lazy += k;
        st[rt].sum += k;
    } else { 
        PushDown(l,r,rt);
        int m = l + (r-l)/2;
        if(L <= m)  update(L,R,k,lch);
        if(m < R)  update(L,R,k,rch);
        PushUp(rt);
    }
}

int queryMAX(int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R){
        return st[rt].sum;
    }
    PushDown(l,r,rt);
    int m = l + (r-l)/2;
    int res  = -1;
    if(L <= m)  res = max(res, queryMAX(L, R, lch));
    if(m < R)  res = max(res, queryMAX(L, R, rch));
    return res;
}

int main(void)
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    build(1,n,1);
    for(int i = 0; i < m; i++){
        int L,R;
        scanf("%d%d", &L, &R);
        if(queryMAX(L, R-1, 1, n ,1) >= k){
            printf("No\n");
        } else{
            update(L,R-1,1,1,n,1);
            printf("Yes\n");
        }
    }
    return 0;
}
