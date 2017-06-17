#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int r,c,dir;
    Node(int rr=0,int cc=0,int ddir=0):r(rr),c(cc),dir(ddir) {}
};

const char* dirs="NESW";
const char* turns="FLR";
const int dr[]= {-1,0,1,0};
const int dc[]= {0,1,0,-1};
char name[100],dir0[4];
int r0,c0,rt,ct,r1,c1,dir;
int d[10][10][4];
Node p[10][10][4];
bool has_edge[10][10][4][3];

int dir_id(char c)
{
    return strchr(dirs,c)-dirs;
}
int turn_id(char c)
{
    return strchr(turns,c)-turns;
}

Node walk(Node& u,int turn)
{
    int dir=u.dir;
    if(turn==0);
    if(turn==1) dir=(dir+3)%4;
    if(turn==2) dir=(dir+1)%4;
    return Node(u.r+dr[dir],u.c+dc[dir],dir);
}

bool inside(int r,int c)
{
    return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}

bool input()
{
    char dirnext[100];
    if(scanf("%s%d%d%s%d%d",name,&r0,&c0,dir0,&rt,&ct)!=6)  return false;

    printf("%s\n",name);

    //初始状态   也就是 r0,c0 位置向上下左右走一步后的状态
    dir=dir_id(dir0[0]);
    r1=r0+dr[dir];
    c1=c0+dc[dir];

    memset(has_edge,0,sizeof(has_edge));
    for(;;)
    {
        int rx,cx;
        scanf("%d",&rx);
        if(!rx) break;
        scanf("%d",&cx);

        while((scanf("%s",dirnext)==1)&&dirnext[0]!='*')
        {
            for(int i=1; i<(int)strlen(dirnext); i++)
                has_edge[rx][cx][dir_id(dirnext[0])][turn_id(dirnext[i])]=1;
        }
    }

    return true;
}

void print_ans(Node u)
{
    vector<Node> nodes;
    for(;;)
    {
        nodes.push_back(u);
        if(d[u.r][u.c][u.dir]==0)   break;
        u=p[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r0,c0,dir));

    int cnt=0;
    for(int i=nodes.size()-1; i>=0; i--)
    {
        if(cnt%10==0)   printf(" ");
        printf(" (%d,%d)",nodes[i].r,nodes[i].c);
        if(++cnt%10==0) printf("\n");
    }
    if(nodes.size()%10!=0)  printf("\n");
}

void bfs()
{
    queue<Node> q;
    memset(d,-1,sizeof(d));
    Node u(r1,c1,dir);
    //d表示的是初始状态到 r,c,dir 这个状态的最短路
    d[u.r][u.c][u.dir]=0;
    q.push(u);
    while(!q.empty())
    {
        Node u=q.front();
        q.pop();

        //到达终点
        if(u.r==rt&&u.c==ct)
        {
            print_ans(u);
            return;
        }

        for(int i=0; i<3; i++)
        {
            Node v=walk(u,i);

            //has_edge r,c,dir 能否 执行 turn
            //d[v.r][v.c][v.dir]<0 这个点并没有走过
            if(has_edge[u.r][u.c][u.dir][i]&&inside(v.r,v.c)&&d[v.r][v.c][v.dir]<0)
            {
                d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1; //能从u到v那么距离+1
                p[v.r][v.c][v.dir]=u;                    //u是v在BFS树中的父结点
                q.push(v);
            }
        }
    }
    //如果能到终点 那么在之前已经print_ans 并且return ;
    printf("  No Solution Possible\n");
}


int main(void)
{
    while(input())
        bfs();
    return 0;
}
