#include<bits/stdc++.h>
using namespace std;

#define mset(x) memset(x,0,sizeof(x))

const int maxn=1000+10;
int D[maxn];
int G[maxn][maxn];
int path[maxn];

int main(void)
{
    ios::sync_with_stdio(false);
    int m,n;
    //n是技能的个数
    //m是有m对
    while(cin>>n>>m){
        mset(D),mset(G),mset(path);
        //读入有向边
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            G[u][v]=1;
            D[v]++; //这里是出度 也就是u<v 那么以v起点的弧数量++ 即 v出度++
        }
        //把度数为0的点先放进优先队列(越小的数优先级越大)
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i=1;i<=n;i++){
            if(!D[i])   q.push(i);
        }

        int l=0;
        while(!q.empty()){
            int cur=q.top();
            path[l++]=cur;
            q.pop();
            //某个点被放入路径了，那么以这个点为终点的弧的起点的出度都-1
            for(int i=1;i<=n;i++){
                if(G[cur][i]){
                    D[i]--;
            //如果某个点的出度是0了，那么就放入路径里
                    if(!D[i])
                        q.push(i);
                }
            }
        }

        for(int i=0;i<l;i++){
            if(i)  cout<<" ";
            cout<<path[i];
        }
        cout<<endl;
    }
    return 0;
}
