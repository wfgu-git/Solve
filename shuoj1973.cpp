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
    int sum[3],lazy,num;
}st[maxn<<2];

void PushUp(int rt)
{
    st[rt].sum[0]=st[rt<<1].sum[0]+st[rt<<1|1].sum[0];
    st[rt].sum[1]=st[rt<<1].sum[1]+st[rt<<1|1].sum[1];
    st[rt].sum[2]=st[rt<<1].sum[2]+st[rt<<1|1].sum[2];
}

void PushDown(int l,int r,int rt)
{
    int times = st[rt].lazy;
    if(times){
        times %= 3;
        for(int i=0; i < times; i++){
            int y0,y1,y2;
            //lch
            y0=st[rt<<1].sum[0];
            y1=st[rt<<1].sum[1];
            y2=st[rt<<1].sum[2];
            st[rt<<1].sum[0] = y2;
            st[rt<<1].sum[1] = y0;
            st[rt<<1].sum[2] = y1;
            st[rt<<1].lazy++;
            //rch
            y0=st[rt<<1|1].sum[0];
            y1=st[rt<<1|1].sum[1];
            y2=st[rt<<1|1].sum[2];
            st[rt<<1|1].sum[0]=y2;
            st[rt<<1|1].sum[1]=y0;
            st[rt<<1|1].sum[2]=y1;
            st[rt<<1|1].lazy++;
        }
    }
    st[rt].lazy=0;
}

void build(int l,int r,int rt)
{
    st[rt].lazy = 0;
    if(l==r){
        st[rt].num=0;
        st[rt].sum[0]=1;
        st[rt].sum[1]=0;
        st[rt].sum[2]=0;
        return ;
    }   
    int m=(l+r)>>1;
    build(lch);
    build(rch);
    PushUp(rt);
}

void update(int L,int R,int k,int l,int r,int rt)
{
    if(L<=l && r<=R){
        st[rt].lazy+=k;
        int y0,y1,y2;
        y0=st[rt].sum[0];
        y1=st[rt].sum[1];
        y2=st[rt].sum[2];
        st[rt].sum[0]=y2;
        st[rt].sum[1]=y0;
        st[rt].sum[2]=y1;
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
        return st[rt].sum[0];
    }
    PushDown(l,r,rt);
    int m=(l+r)>>1;
    int res=0;
    if(L <= m)  res += query(L,R,lch);
    if(R > m)  res += query(L,R,rch);
    return res;
}

int main(void)
{
    int n,q;
    scanf("%d%d",&n,&q);
    build(1,n,1);
    for(int i=0;i<q;i++){
        int tag,L,R;
        scanf("%d%d%d",&tag,&L,&R);
        if(tag==0){
            update(L,R,1,1,n,1); 
        } else{
            printf("%d\n",query(L,R,1,n,1));
        } 
    }
    return 0;
}
