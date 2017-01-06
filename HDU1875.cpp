/*************************************************************************
	> File Name: HDU1875.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月06日 星期五 15时53分46秒
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
const int maxn=205;
const int INF=1000000;
double dis[maxn];
bool vis[maxn];
struct Node{
    int u,v;
}node[maxn];

double getdis(int i,int j)
{
    return sqrt( (node[i].u-node[j].u) * (node[i].u-node[j].u)
                +(node[i].v-node[j].v) * (node[i].v-node[j].v) );
}

bool checkdis(double x)
{
    if(x<10||x>1000)    return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=n;i++){
            cin>>node[i].u>>node[i].v;
        }
        
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));

        double sum=0;
        vis[1]=true;
        int index=1;

        for(int i=1;i<=n;i++){
            dis[i]=getdis(1,i);
        }

        for(int i=1;i<=n;i++){
            double mincost=INF;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&checkdis(dis[j])&&dis[j]<mincost){
                    mincost=dis[j];
                    index=j;
                }
            }

            if(checkdis(mincost)){
            sum+=mincost;
            vis[index]=true;
            }
            //更新dis
            for(int j=1;j<=n;j++){
                if(!vis[j]&&dis[j]>getdis(index,j)&&checkdis(getdis(index,j))){
                    dis[j]=getdis(index,j);
                }
            }

        }
        int cnt=0; 
        for(const bool & v : vis) {if(v) cnt++;}
        if(cnt==n)    cout<<fixed<<setprecision(1)<<sum*100<<endl;
        else    cout<<"oh!"<<endl;
    }
    return 0;
}
