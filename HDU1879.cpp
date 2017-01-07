/*************************************************************************
	> File Name: HDU1879.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 23时28分33秒
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

struct Edge{
    int from,to;
    int value;
    bool ok;
}node[5050];

bool cmp(Edge a,Edge b){
    return a.value<b.value;
}

int fa[105];

void init(int n)
{
    for(int i=0;i<=n;i++)    fa[i]=i;
}

int find(int x)
{
    if(x!=fa[x])    fa[x]=find(fa[x]);
    return fa[x];
}

void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return ;
    fa[a]=b;
}

int main(void)
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n&&n){
        m=n*(n-1)/2;
        init(n);
        int ans=0;
        for(int i=1;i<=m;i++){
            cin>>node[i].from>>node[i].to>>node[i].value>>node[i].ok;
            if(node[i].ok==1)    node[i].value=0;
        }

        sort(node+1,node+m+1,cmp);

        for(int i=1;i<=m;i++){
            int u=find(node[i].from);
            int v=find(node[i].to);
            if(u==v)    continue;
            fa[u]=v;
            ans+=node[i].value;
        }
        cout<<ans<<endl;
    }
    return 0;
}
