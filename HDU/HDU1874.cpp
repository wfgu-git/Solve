/*************************************************************************
	> File Name: HDU1874.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 22时36分59秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define fi first
#define se second

const int maxn=220;
const int INF=0x3f3f3f3f;
vector<pair<int,int> > G[maxn];
int dist[maxn];
bool vis[maxn];

void add_edge(int u,int v,int d)
{
    G[u].push_back(MP(v,d));
}

void spfa(int start,int n)
{
//start 起点
//n the num of the node
//dist[i] start to i  min
//queue q input node
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[start]=0;

    for(int i=0;i<n;i++){
        vis[i]=false;
    }   
    
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur=q.front();q.pop();
        vis[cur]=false;
        for(int i=0;i<(int)G[cur].size();i++){
            int v=G[cur][i].fi;
            int d=G[cur][i].se;
            if(dist[cur]+d<dist[v]){
                dist[v]=dist[cur]+d;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<=n;i++)    G[i].clear();

        for(int i=1;i<=m;i++){
            int u,v,d;
            cin>>u>>v>>d;
            add_edge(u,v,d);
            add_edge(v,u,d);
        }
        int start,end;
        cin>>start>>end;
        spfa(start,n);
        if(dist[end]==INF)    cout<<-1<<endl;
        else
            cout<<dist[end]<<endl;

    }
    return 0;
}
