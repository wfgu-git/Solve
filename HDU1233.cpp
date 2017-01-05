/*************************************************************************
	> File Name: HDU1233.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月05日 星期四 18时12分09秒
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
const int maxn=5010;
int fa[maxn];

struct Node
{
        int u,v,value;

}node[maxn];

bool cmp(Node a,Node b){
    if(a.value<b.value)
        return true;
    return false;
}
void init(int n){
    for(int i=1;i<=n;i++)   fa[i]=i;
}

int find(int x){
    if(x!=fa[x])    fa[x]=find(fa[x]);
    return fa[x];
}

//void Union(int a,int b)
//{
//        a=find(a);
//        b=find(b);
//        if(a==b)    return ;
//        fa[a]=b;
//}
//
int main(void)
{
        ios::sync_with_stdio(false);
        int n,k;
    while(cin>>n&&n){
                init(n);
                int ans=0;
                k=n*(n-1)/2;
        for(int i=1;i<=k;i++){
                    cin>>node[i].u>>node[i].v>>node[i].value;
        }
                sort(node+1,node+k+1,cmp);
        for(int i=1;i<=k;i++){
                        int x=find(node[i].u);
                        int y=find(node[i].v);
                        if(x==y)   continue;
                        ans+=node[i].value;
                        fa[y]=x;
                    
        }
                cout<<ans<<endl;
            
    }
        return 0;

}

