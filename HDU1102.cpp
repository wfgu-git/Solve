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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const int maxn=110;
int G[maxn][maxn];
int dist[maxn];
bool vis[maxn];
int n;
int prim()
{
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    int sum=0;

    for(int i=1;i<=n;i++){
        dist[i]=G[1][i];
    }
    
    vis[1]=false;
    for(int i=1;i<=n;i++){
        int mincost=INF;
        int index;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&mincost>dist[j]){
                mincost=dist[j];
                index=j;
            }
        }

        vis[index]=true;
        sum+=dist[index];

        for(int j=1;j<=n;j++)
            if(!vis[j]&&dist[j]>G[index][j])
                dist[j]=G[index][j];
    
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n){
        //input
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>G[i][j];
        int q;
        cin>>q;
        while(q--){
            int u,v;
            cin>>u>>v;
            G[u][v]=0;
            G[v][u]=0;
        }
        
        cout<<prim()<<endl;
    }
    return 0;
}
