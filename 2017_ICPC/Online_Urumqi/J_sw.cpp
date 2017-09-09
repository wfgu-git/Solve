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
#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf(a) scanf("%lf",&a)
#define sf2(a,b) scanf("%lf%lf",&a,&b)
#define mp(a,b) make_pair(a,b)
#define maxn 10005
using namespace std;
typedef long long ll;
ll dis[maxn<<3];
int vis[maxn<<3];
map<string,int>ma;
queue<int>que;
struct Edge{
    int to,nxt,cap;
    ll cost;
}edge[maxn<<6];
int tot = 0,head[maxn<<3],pa[maxn<<3];
void addedge(int u, int v, ll cost, int cap){
    edge[tot].to = v, edge[tot].nxt = head[u], edge[tot].cost = cost, edge[tot].cap = cap;
    head[u] = tot++;
    edge[tot].to = u, edge[tot].nxt = head[v], edge[tot].cost = -cost, edge[tot].cap = 0;
    head[v] = tot++;
}
int s,t;
int m;
int node = 0;
int addflow(int s, int t){
    int cur = t, ans = 1e9;
    while(cur!=s){
        ans = min(ans,edge[pa[cur]].cap);
        cur = edge[pa[cur]^1].to;
    }
    cur = t;
    while(cur!=s){
        edge[pa[cur]].cap-=ans;
        edge[pa[cur]^1].cap+=ans;
        cur = edge[pa[cur]^1].to;
    }
    return ans;
}
ll mincost,flow;
bool spfa(int s, int t){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < node*2; i++)dis[i] = 1e18;
    memset(pa, -1, sizeof(pa));
    while(!que.empty())que.pop();
    que.push(s);vis[s] = 1;dis[s] = 0;
    while(!que.empty()){
        int cur = que.front();que.pop();
        vis[cur] = 0;
        for(int i = head[cur]; i != - 1; i = edge[i].nxt){
            int v = edge[i].to;
            if(dis[v] > dis[cur] + edge[i].cost&&edge[i].cap){
//                cout << "::"<<v <<endl;
                dis[v] = dis[cur] + edge[i].cost;
                pa[v] = i;
                if(!vis[v])vis[v] = 1, que.push(v);
            }
        }
    }
    if(dis[t] > 1e17)return 0;
    int F = 0;
    F = addflow(s,t);
    flow+=F;
    mincost += (ll)F * dis[t];
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    int T;
    string a,b;
    cin >> T;
    while(T--){
        flow = mincost = 0;
        ma.clear();
        node = 0;
        tot = 0;
        memset(head, -1, sizeof(head));
        cin >> m;
        for(int i = 0; i < m; i++){
            ll x;
            cin >> a >> b >> x;
            if(ma.count(a)==0){
                ma[a] = 2*(node++);
                int num = 1;
                if(a=="Shanghai")num = 2;
                addedge(ma[a]+1, ma[a], 0,num);
            }
            if(ma.count(b)==0){
                ma[b] = 2*(node++);
                int num = 1;
                if(b=="Shanghai")num = 2;
                addedge(ma[b]+1, ma[b], 0,num);
            }
            addedge(ma[a], ma[b]+1, x,1);
            addedge(ma[b], ma[a]+1, x,1);
        }
        s = 2*(node++); t = s+1;
        if(ma.count("Dalian")==0||ma.count("Shanghai")==0||ma.count("Xian")==0){
            cout << -1 << endl;
            continue;
        }
        addedge(s, ma["Dalian"]+1, 0, 1);
        addedge(s, ma["Xian"]+1, 0, 1);
        addedge(ma["Shanghai"], t, 0, 2);
        while(spfa(s,t));
        if(flow==2) cout << mincost << endl;
        else cout << -1 << endl;
    }
    return 0;
}
