/*************************************************************************
	> File Name: POJ2387.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月08日 星期日 16时52分08秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn=2020;
const int INF=0x3f3f3f3f;
typedef pair<int,int> PII;
#define MP(a,b) make_pair(a,b)
bool vis[maxn];
int dist[maxn];
vector<PII> G[maxn];

void add_edge(int u,int v,int d)
{
    G[u].push_back(MP(v,d));
}

void spfa(int start,int n)
{
    for(int i=0;i<=n;i++){vis[i]=false;}

    for(int i=0;i<n;i++){dist[i]=INF;}
    dist[start]=0;

    queue<int> q;
    q.push(start);
   
    while(!q.empty()){
        int cur=q.front();q.pop();
        vis[cur]=false;
        for(int i=0;i<(int)G[cur].size();i++){
            int v=G[cur][i].first;
            int d=G[cur][i].second;
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
    while(cin>>m>>n){
        for(int i=0;i<n;i++) G[i].clear();
        
        for(int i=0;i<m;i++){
            int from,to,value;
            cin>>from>>to>>value;
            add_edge(from-1,to-1,value);
            add_edge(to-1,from-1,value);
        }
        spfa(0,n);
        cout<<dist[n-1]<<endl;
    }
    return 0;
}
