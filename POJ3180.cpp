/*************************************************************************
	> File Name: POJ3180.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 22时26分20秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MEM(a) memset(a,0,sizeof(0))
const int maxn=20010;
vector<int> G[maxn];
int pre[maxn],low[maxn],sccno[maxn],ans[maxn],dfs_clock,scc_cnt;
stack<int> S;

//ans来计算 点数大于1个的强连通分量的个数

void dfs(int u)
{
    pre[u]=low[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(!pre[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v]){
            low[u]=min(low[u],pre[v]);
        }
    }

    if(low[u]==pre[u]){
        scc_cnt++;
        while(1){
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x==u)
                break;
        }
    }
}

void find_scc(int n)
{
    scc_cnt=dfs_clock=0;
    MEM(sccno);MEM(pre);MEM(ans);
    for(int i=1;i<=n;i++){
        if(!pre[i])
            dfs(i);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            G[a].push_back(b);
        }
        find_scc(n);
        for(int i=1;i<=n;i++){
            ans[sccno[i]]++;
        }
        int cnt=0;
        for(int i=1;i<=scc_cnt;i++){
            if(ans[i]>1)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
