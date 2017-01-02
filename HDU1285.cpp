#include<bits/stdc++.h>
using namespace std;
#define MEM(x) memset(x,0,sizeof(x))

const int maxn=500+10;
int D[maxn];
int G[maxn][maxn];
int path[maxn];


int main(void)
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        MEM(D);
        MEM(G);
        MEM(path);
        int u,v;
        for(int i=1; i<=m; i++)
        {
            cin>>u>>v;
            if(G[u][v]==0)
            {
                G[u][v]=1;
                D[v]++;
            }
        }

        priority_queue<int,vector<int>,greater<int> > q;
        for(int i=1; i<=n; i++)
        {
            if(!D[i])
                q.push(i);
        }

        int p=0;
        while(!q.empty())
        {
            int cur=q.top();
            q.pop();
            path[p++]=cur;
            for(int i=1; i<=n; i++)
            {
                if(G[cur][i])
                {
                    G[cur][i]--;
                    D[i]--;
                    if(!D[i])
                        q.push(i);
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(i)   cout<<" ";
            cout<<path[i];
        }
        cout<<'\n';
    }
    return 0;
}
