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
int G[105][105];
int deg[105];
vector<int> cnt;
bool toposort(int n)
{
    queue<int> q;
    cnt.clear();
    for(int i=0;i<n;i++){
        if(!deg[i]) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        cnt.push_back(cur);
        for(int i=0;i<n;i++){
            if(G[cur][i]){
                if(!--deg[i]){
                    q.push(i);
                }
            }
        }
    }
    if((int)cnt.size()<n) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        memset(G,0,sizeof(G));
        memset(deg,0,sizeof(deg));
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            G[u][v]=1;
            deg[v]++;
        }
        
        if(toposort(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
