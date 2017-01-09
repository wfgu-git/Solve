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
const int maxn=110;
const int INF=0x3f3f3f3f;
double cost[maxn][maxn];
double mincost[maxn];
bool used[maxn];
int n;

struct Node{
    double x,y;
}node[maxn];

double getdis(int a,int b)
{
    return sqrt( (node[a].x-node[b].x) * (node[a].x-node[b].x)
                +(node[a].y-node[b].y) * (node[a].y-node[b].y) );
}


double prim()
{
    for(int i=0;i<n;i++){
        mincost[i]=INF;
        used[i]=false;
    }
    for(int i=0;i<n;i++){
    }
    mincost[0]=0;
    double ans=0;
    while(true){
        int v=-1;
        for(int u=0;u<n;u++)
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])){   
                v=u;
            }

        if(v==-1)    break;
        used[v]=true;
        ans+=mincost[v];

        for(int u=0;u<n;u++){
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n){
    for(int i=0;i<n;i++){cin>>node[i].x>>node[i].y;}

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=getdis(i,j);
        }
    }

    cout<<fixed<<setprecision(2)<<prim()<<endl;
    }
    return 0;
}
