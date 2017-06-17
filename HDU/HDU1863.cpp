/*************************************************************************
	> File Name: HDU1863.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月06日 星期五 14时29分12秒
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
const int maxn=5050;
int fa[105];

struct Edge{
    int from,to,value;
}edge[maxn];
bool cmp(Edge a,Edge b){return a.value<b.value;}

void init(int n)
{
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
}

int find(int x)
{
    if(x!=fa[x])    fa[x]=find(fa[x]);
    return fa[x];
}


int main(void)
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>m>>n&&m){
        init(n);
        int ans=0,cnt=0;
        for(int i=1;i<=m;i++){
            cin>>edge[i].from>>edge[i].to>>edge[i].value;
        }

        sort(edge+1,edge+m+1,cmp);

        for(int i=1;i<=m;i++){
            int u=find(edge[i].from);
            int v=find(edge[i].to);
            if(u==v)    continue;
            ans+=edge[i].value;
            fa[u]=v;
        }
        
        for(int i=1;i<=n;i++){
            if(i==find(i))    cnt++;
        }

        if(cnt>1)    cout<<"?"<<endl;
        else    cout<<ans<<endl;
    }
    return 0;
}
