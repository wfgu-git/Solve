#include<bits/stdc++.h>
using namespace std;

//#define mset(x) memset(x,0,sizeof(x))

const int maxn=10000+10;
int OD[maxn];
vector<int> path;
vector<vector<int> >G;
int n,m;
char c;

int main(void)
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        bool flag=true;
        //ini
        G.clear();
        path.clear();
        for(int i=0;i<n;i++){
            OD[i]=0;
        }

        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>c>>v;
            if(c=='<')  {G[u][v]=1;OD[v]++;}
            else if(c=='>') {G[v][u]=1;OD[u]++;}
            else    {G[u][v]=1;G[v][u]=1;OD[u]++;OD[v]++;}
        }

        queue<int> q;

        for(int i=n-1;i>=0;i--){
            if(!OD[i])   q.push(i);
        }

        while(!q.empty()){
            if(q.size()>1)  flag=false;
            int cur=q.front();
            path.push_back(cur);
            q.pop();
            for(int i=n-1;i>=0;i--){
                if(G[cur][i]){
                    OD[i]--;
                    if(!OD[i])
                        q.push(i);
                }
            }
        }
        if(!flag)  {cout<<"UNCERTAIN"<<endl;continue;}
        if((int)path.size()<n)   {cout<<"CONFLICT"<<endl;continue;}
        cout<<"OK"<<endl;
    }
    return 0;
}
