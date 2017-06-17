/*************************************************************************
	> File Name: HDU2544.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 23时58分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<iomanip>
#include<functional>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> PII;
#define MP(a,b) make_pair(a,b)
#define fi first
#define se second
const int INF=0x3f3f3f3f;
const int maxn=10010;

vector<PII> G[maxn];
int dist[maxn];
bool vis[maxn];

void add_edge(int u,int v,int d)
{
    G[u].push_back(MP(v,d));
}

void spfa(int start, int n)
{
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
                //如果 起点到cur加cur到v(d) 距离< 起点到v的距离 则 更新
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
    while(cin>>n>>m&&(n+m)){
        for(int i=0;i<n;i++)    G[i].clear();
        for(int i=1;i<=m;i++){
            int u,v,d;
            cin>>u>>v>>d;
            add_edge(u-1,v-1,d);
            add_edge(v-1,u-1,d);
        }
        spfa(0,n);
        cout<<dist[n-1]<<endl;
    }
}
