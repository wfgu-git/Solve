#include <bits/stdc++.h>
#define maxn 500010
#define inf 0x3f3f3f3f
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int nxt[maxn*64][2],n,tot,root,SizeR[maxn*64+10],SizeL[maxn*64+10],a[maxn];
ll ans0[34],ans1[34];
inline int newnode(){
    nxt[tot][0]=nxt[tot][1]=-1;
    SizeL[tot]=SizeR[tot]=0;
    tot++;
    return tot-1;
}
void Insert(int x){
    int now=root;
    RREP(i,31,-1){
        int tmp=((x>>i)&1);
        if(nxt[now][tmp]==-1) nxt[now][tmp]=newnode();
        now=nxt[now][tmp];
        SizeR[now]++;
    }
}
ll query(int x){
    int now=root;
    ll ans=0;
    RREP(i,31,-1){
        int tmp=((x>>i)&1);
        SizeR[nxt[now][tmp]]--;
        if(tmp){        //1  L 1 R 0
            ans+=ans1[i];
            ans1[i]+=SizeR[nxt[now][0]];
            ans0[i]-=SizeL[nxt[now][0]];
        }
        else {
            ans+=ans0[i];
            ans0[i]+=SizeR[nxt[now][1]];
            ans1[i]-=SizeL[nxt[now][1]];
        }
        SizeL[nxt[now][tmp]]++;
        now=nxt[now][tmp];
    }
    return ans;
}
int main()
{
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
    int T;scanf("%d",&T);
    while(T--){
        memset(ans0,0,sizeof(ans0));
        memset(ans1,0,sizeof(ans1));
        tot=0;
        root=newnode();
        scanf("%d",&n);
        REP(i,1,n+1) {
            scanf("%d",&a[i]);
            Insert(a[i]);
        }
        ll ans=0;
        REP(i,1,n+1)
            ans+=query(a[i]);
        printf("%I64d\n",ans);
    }
}
