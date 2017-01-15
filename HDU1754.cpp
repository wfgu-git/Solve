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
#define lch l,mid,root<<1
#define rch mid+1,r,root<<1|1
const int maxn=200010;
int n,m;
int sum[maxn<<2];

void push_up(int root){
    sum[root]=max(sum[root<<1],sum[root<<1|1]);
}
void build(int l,int r,int root){
    if(l==r){
        scanf("%d",&sum[root]);    
        return ;
    }
    int mid=(l+r)>>1;
    build(lch);
    build(rch);
    push_up(root);
}
//单点更新 
void update(int p,int k,int l,int r,int root){
    if(l==r){
        sum[root]=k;
        return ;
    }
    int mid=(l+r)>>1;
    if(p<=mid) update(p,k,lch);
    else update(p,k,rch); 
    push_up(root);
}

int queryMAX(int L,int R,int l,int r,int root){
    if(l>=L&&r<=R){
        return sum[root]; 
    }
    int mid=(l+r)>>1;
    int ret=-1;
    if(L<=mid) ret=max(ret,queryMAX(L,R,lch));
    if(R>mid)  ret=max(ret,queryMAX(L,R,rch));
    return ret;
}

int a,b;
int main()
{
    while(cin>>n>>m){
        MEM(sum,0);
        build(1,n,1); 
        for(int i=1;i<=9;i++){
            cout<<"root no."<<i<<":\n";
            cout<<sum[i]<<endl;
        }
        char op[2];
        for(int i=0;i<m;i++){
            scanf("%s%d%d",op,&a,&b);
            if(op[0]=='Q') 
            cout<<queryMAX(a,b,1,n,1)<<endl;
            else if(op[0]=='U')
            update(a,b,1,n,1);
        }
    }
    return 0;
}
