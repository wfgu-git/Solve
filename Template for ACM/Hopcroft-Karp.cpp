#include<iostream>                                                                                                         
 #include<queue>
 using namespace std;
 const int MAXN=500;// 最大点数
 const int INF=1<<28;// 距离初始值
 int bmap[MAXN][MAXN];//二分图

 int cx[MAXN];//cx[i]表示左集合i顶点所匹配的右集合的顶点序号
 int cy[MAXN]; //cy[i]表示右集合i顶点所匹配的左集合的顶点序号

 int nx,ny;
 int dx[MAXN];
 int dy[MAXN];
 int dis;
 bool bmask[MAXN];
 //寻找 增广路径集
 bool searchpath()
 {
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=1;i<=nx;i++)
    {
       //cx[i]表示左集合i顶点所匹配的右集合的顶点序号
       if(cx[i]==-1)
       {
          //将未遍历的节点 入队 并初始化次节点距离为0
          Q.push(i);
          dx[i]=0;
       }
    }
    //广度搜索增广路径
    while(!Q.empty())
    {
       int u=Q.front();
       Q.pop();
       if(dx[u]>dis) break;
       //取右侧节点
       for(int v=1;v<=ny;v++)
       {
          //右侧节点的增广路径的距离
          if(bmap[u][v]&&dy[v]==-1)
          {
             dy[v]=dx[u]+1; //v对应的距离 为u对应距离加1
             if(cy[v]==-1) dis=dy[v];
             else
             {
                dx[cy[v]]=dy[v]+1;
                Q.push(cy[v]);
             }
          }
       }
    }
    return dis!=INF;
 }

 //寻找路径 深度搜索
 int findpath(int u)
 {
    for(int v=1;v<=ny;v++)
    {
       //如果该点没有被遍历过 并且距离为上一节点+1
       if(!bmask[v]&&bmap[u][v]&&dy[v]==dx[u]+1)
       {
          //对该点染色
          bmask[v]=1;
          if(cy[v]!=-1&&dy[v]==dis)
          {
             continue;
          }
          if(cy[v]==-1||findpath(cy[v]))
          {
             cy[v]=u;cx[u]=v;
             return 1;
          }
       }
    }
    return 0;
 }

 //得到最大匹配的数目
 int MaxMatch()
 {
    int res=0;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    while(searchpath())
    {
       memset(bmask,0,sizeof(bmask));
       for(int i=1;i<=nx;i++)
       {
          if(cx[i]==-1)
          {
             res+=findpath(i);
          }
       }
    }
    return res;
 }


 int main()
 {
    int num;
    scanf("%d",&num);
    while(num--)
    {

       memset(bmap,0,sizeof(bmap));
       scanf("%d%d",&nx,&ny);
       for(int i=1;i<=nx;i++)
       {
          int snum;
          scanf("%d",&snum);
          int u;
          for(int j=1;j<=snum;j++)
          {
             scanf("%d",&u);
             bmap[i][u]=1;
            // bmap[u][i]=1;
          }
       }
      // cout<<MaxMatch()<<endl;
       if(MaxMatch()==nx)
       {
          printf("YES\n");
       }
       else
       {
          printf("NO\n");
       }
    }
    //system("pause");
    return 0;
 }

 /*

4
1 3
1 3 4
2


 */
