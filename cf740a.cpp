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
const ll INF = LONG_MAX;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn=4;
bool vis[maxn];
ll dist[maxn];
ll G[maxn][maxn];

void spfa(ll start)
{
    MEM(vis,0);
    for(int i=0;i<4;i++) dist[i]=INF;
    dist[start]=0;

    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            if(G[cur][i]&&G[cur][i]+dist[cur]<dist[i]){
                dist[i]=dist[cur]+G[cur][i];
                if(!vis[i]){
                vis[i]=true;
                q.push(i);
                }
            }
            vis[cur]=false;
        } 
    } 
}

int main()
{
    ios::sync_with_stdio(false);
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    if(n%4==0) {cout<<0<<endl; return 0;}
    // G[i][j]  
    
    G[0][1]=c,G[0][2]=b,G[0][3]=a,G[1][2]=c,G[1][3]=b,G[2][1]=a,G[2][3]=c,G[3][1]=b,G[3][2]=a;
    spfa(0);
    cout<<dist[n%4]<<endl;
    return 0;
}
