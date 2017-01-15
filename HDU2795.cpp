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
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1

int Max(int a,int b){
    return a>b?a:b;
}
const int maxn=200005;

int w,h,n; 
int MAX[maxn<<2];
void push_up(int rt){
    MAX[rt]=Max(MAX[rt<<1],MAX[rt<<1|1]);
}

void build(int l,int r,int rt){
    if(l==r){    
        MAX[rt]=w;
        return ;
    }
    int m=(l+r)>>1;
    build(lch);
    build(rch);
    push_up(rt);
}

int update(int k,int l,int r,int rt){
    if(MAX[rt]<k) return -1;
    if(r==l){
        MAX[rt]-=k;
        return l;
    }
    int m=(l+r)>>1;
    int res;
    if(MAX[rt<<1]>=k)    res=update(k,lch);
    else    res=update(k,rch);
    push_up(rt);
    return res;
}


int main()
{
    while(~scanf("%d%d%d",&h,&w,&n)){
        if(h>maxn) h=maxn;
        build(1,h,1);        
        for(int i=0;i<n;i++){
            int wi;
            scanf("%d",&wi);
            printf("%d\n",update(wi,1,h,1));
        }
    } 
    return 0;
}
