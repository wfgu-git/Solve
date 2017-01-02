#include<bits/stdc++.h>
using namespace std;
#define MP(a,b) make_pair(a,b)
#define MEM(x) memset(x,0,sizeof(x))

typedef pair<int,int> PII;
typedef vector<int> Vint;
typedef long long ll;
const int maxn=10000+10;
int deg[maxn];
map<PII,bool> S;
Vint G[maxn];
map<int,int> money;
int ans;

bool toposort(int n){
    int tot=0;
    ans=0;
    queue<pair<int,ll> > q;

    for(int i=0;i<n;i++){
        if(!deg[i])
            q.push(MP(i,888));
    }

    while(!q.empty()){
        int cur=q.front().first;
        int d=q.front().second;
        ans+=d;
            q.pop();tot++;
            for(int i=0;i<(int)G[cur].size();i++){
                int v=G[cur][i];
                if(!--deg[v]){
                    q.push(MP(v,d+1));
                }
            }
    }
    if(tot<n) //ÐÎ³É»·   return false;
    return true;
}

int main(void)
{
    int m,n;
    while(cin>>n>>m){
        //init
        MEM(deg);
        for(int i=0;i<n;i++)G[i].clear();
        S.clear();

        //input
        while(m--){
            int uu,vv;
            cin>>vv>>uu;
            int u=uu-1;
            int v=vv-1;
            if(S[MP(u,v)]){
                ans=-1;
                continue;
            }
            S[MP(u,v)]=1;
            G[u].push_back(v);
            deg[v]++;
        }

        if(!toposort(n))    ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}
