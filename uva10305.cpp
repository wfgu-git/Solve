//#include<bits/stdc++.h>
//using namespace std;
//
//#define mset(x) memset(x,0,sizeof(x))
//
//const int maxn=1000+10;
//int D[maxn];
//int G[maxn][maxn];
//int path[maxn];
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    int m,n;
//    while(cin>>n>>m&&(m+n)){
//        mset(D);mset(G);mset(path);
//        int u,v;
//        for(int i=1;i<=m;i++){
//            cin>>u>>v;
//            G[u][v]=1;
//            D[v]++;
//        }
//
//        queue<int> q;
//        for(int i=1;i<=n;i++)    if(!D[i])   q.push(i);
//
//        int p=0;
//        while(!q.empty()){
//            int cur=q.front();
//            path[p++]=cur;
//            q.pop();
//            for(int i=1;i<=n;i++){
//                if(G[cur][i]){
//                    if(!--D[i])
//                        q.push(i);
//                }
//            }
//        }
//
//        for(int i=0;i<n;i++){
//            if(i)   cout<<" ";
//            cout<<path[i];
//            }
//        cout<<endl;
//    }
//    return 0;
//}


//dfs

#include<bits/stdc++.h>
using namespace std;
#define mset(x) memset(x,0,sizeof(x))

const int maxn=1000+10;
int c[maxn];
//保存状态 1已经访问过，且它后面的点都已经递归访问过
//        -1正在访问
//         0从来没有访问过的点
int G[maxn][maxn];
int topo[maxn];
int t,m,n;
bool dfs(int u)
{
    c[u]=-1;
    for(int v=1;v<=n;++v){
        if(G[u][v]){
            if(c[v]==-1)  return false;
            //v是排在u后的点 如果 c[v]<0 说明我在进入dfs(u)之前是调用过dfs(v)的。
            //就是说v u 之间是形成一个环的!
            else if(!c[v]&&!dfs(v)) return false;
        }
    }
    c[u]=1;
    topo[--t]=u;
    //因为是递归调用的，所以这个u其实是走到最后一个点逆着赋值过来的。！！！
    return true;
}

bool toposort(){
    t=n;
    mset(c);
    for(int i=1;i<=n;++i)
        if(!c[i]&&!dfs(i))
            return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    //int n,m;
    while(cin>>n>>m&&(m+n)){
        mset(G);mset(topo);
        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            G[u][v]=1;
        }
        toposort();
        for(int i=0;i<n;i++){
            if(i) cout<<" ";
            cout<<topo[i];
        }
        cout<<endl;
    }
    return 0;
}
