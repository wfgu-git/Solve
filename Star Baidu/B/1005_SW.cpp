#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<string>
#include<cstring>
#include<deque>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#define sf(a) scanf("%lf",&a)
#define sd1(a) scanf("%lld",&a)
#define sd2(a,b) scanf("%lld%lld",&a,&b)
#define sd3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sf(a) scanf("%lf",&a)
#define sf2(a,b) scanf("%lf%lf",&a,&b)
#define mp(a,b) make_pair(a,b)
#define maxn 3003
#define maxm 30004
using namespace std;
typedef long long ll;
ll n,m;
ll head[maxn],tot;
struct Edge{
    ll v,nxt,cap,cost;
}edge[maxm<<1];
ll dis[maxn],vis[maxn], pa[maxn],mincost;
inline void addedge(ll u, ll v, ll cap = 1e9, ll cost = 1){
    edge[tot].v = v;edge[tot].nxt = head[u];edge[tot].cap = cap;edge[tot].cost =cost;
    head[u] = tot++;
}
queue<ll>que;
ll addflow(ll s, ll t){
    ll cur = t, ans = 1e9;
    while(cur!=s){
        //        cout << edge[pa[cur]^1].v<<" "<<edge[pa[cur]].v<<endl;
        ans = min(ans,edge[pa[cur]].cap);
        cur = edge[pa[cur]^1].v;
    }
    cur = t;
    while(cur!=s){
        edge[pa[cur]].cap-=ans;
        edge[pa[cur]^1].cap+=ans;
        cur = edge[pa[cur]^1].v;
    }
    return ans;
}
bool spfa(ll s, ll t){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <=maxn;i++)dis[i]=1e15;
    memset(pa, -1, sizeof(pa));
    while(!que.empty())que.pop();
    que.push(s);vis[s] = 1;dis[s] = 0;
    while(!que.empty()){
        ll cur = que.front();que.pop();
        vis[cur] = 0;
        for(ll i = head[cur]; i != - 1; i = edge[i].nxt){
            ll v = edge[i].v;
            if(dis[v] > dis[cur] + edge[i].cost&&edge[i].cap){
                dis[v] = dis[cur] + edge[i].cost;
                pa[v] = i;
                if(!vis[v])vis[v] = 1, que.push(v);
            }
        }
    }
    if(dis[t] > 1e14||dis[t]>=0)return 0;
    ll flow = addflow(s,t);
    mincost += flow * dis[t];
    return 1;
}
ll fh[maxn],th[maxn];
ll cost[maxn],price[maxn];
int main(){
  freopen("data.in", "r", stdin);
    while(sd2(n, m)==2){
        memset(head, -1, sizeof(head));
        tot = 0;mincost = 0;
        for(ll i = 1; i<= n; i++){
            ll x,y,z,w;
            sd2(x, y);
            sd2(z, w);
            // cost[i] = x, price[i] = z;
            // fh[i] = y, th[i] = w;
            addedge(0, i*2-1,y,x);
            addedge(i*2-1,0 ,0,-x);
            addedge(i*2,2*n+1,w,-z);
            addedge(2*n+1,i*2,0,z);
        }
        for(ll i = 0; i < m; i++){
            ll from,to,distt;
            sd3(from, to, distt);
            addedge(from*2-1, to*2,1e15,distt);
            addedge(to*2, from*2-1,0,-distt);
            addedge(to*2-1, from*2,1e15,distt);
            addedge(from*2, to*2-1,0,-distt);
        }
        for(ll i = 1; i <= n; i++){
            addedge(i*2-1,i*2,1e15,0);
            addedge(i*2,i*2-1,0,0);
            addedge(i*2,i*2-1,1e15,0);
            addedge(i*2-1,i*2,0,0);
        }
        while(spfa(0,2*n+1));
        printf("%lld\n",-mincost);
    }
    return 0;
}
