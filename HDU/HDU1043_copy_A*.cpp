#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

char input[1000],t[1000],op[5];
int c[10];
struct Node
{
    int s,p;
    int f,g,h;
    Node(){}
    Node(int S,int P,int G,int H)
    {
        s=S,p=P;
        g=G,h=H;
        f=g+h;
    }
    bool operator < (const Node &a) const {
        return f>a.f;
    }
};

struct Path
{
    int from,dir;
}path[400000];
int flag[400000];
int G[400000];

int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
string d = "udlr";

priority_queue<Node>Q;
int ans;

stack<int>S;

int getnum()
{
    int res=0;
    for(int i=0;t[i];i++)
        for(int j=i+1;t[j];j++)
            if(t[j]<t[i]) res=res+c[8-i];
    return res;
}

void getstr(int val)
{
    int tmp[10],flag[10];
    memset(flag,0,sizeof flag);
    for(int i=0;i<9;i++) tmp[i]=val/c[8-i],val=val%c[8-i];
    for(int i=0;i<9;i++)
    {
        int num=0;
        for(int j=0;j<9;j++)
        {
            if(flag[j]==0) num++;
            if(num==tmp[i]+1)
            {
                t[i]=j+'0'+1; if(t[i]=='9') t[i]='x';
                flag[j]=1;break;
            }
        }
    }
}

bool g(int a, int b)
{
    if (a>=0 && a<=2 && b>=0 && b<=2) return 1;
    return 0;
}

void read()
{
    t[0]=op[0];
    for(int i=1;i<=8;i++) {scanf("%s",op); t[i]=op[0];}
    for(int i=0;i<=9;i++) input[i]=t[i];
}

void init()
{
    memset(G,-1,sizeof G);
    memset(flag,0,sizeof flag);
    while(!Q.empty()) Q.pop();
}

int H(int val)
{
    char tmp[10];
    for(int i=0;i<=9;i++) tmp[i]=t[i];

    getstr(val);

    int res=0;
    for(int i=0;i<9;i++)
    {
        if(i<8) if(t[i]-'0'!=i+1) res++;
        if(i==8&&t[i]!='x') res++;
    }

    for(int i=0;i<=9;i++) t[i]=tmp[i];
    return res;
}

void A_star(int s,int pos)
{
    flag[s]=2; G[s]=0;
    path[s].from=-1;
    path[s].dir=-1;
    Q.push(Node(s,pos,0,H(s)));
    while(!Q.empty())
    {
        Node h=Q.top(); Q.pop(); flag[h.s]=2;
        getstr(h.s);
        if(h.s==0)
        {
            ans=1; int now=h.s;
            while(1)
            {
                if(path[now].from==-1) return;
                S.push(path[now].dir);
                now=path[now].from;
            }
        }

        int a=h.p/3,b=h.p%3;

        for(int i=0;i<4;i++)
        {
            int x=a+dir[i][0],y=b+dir[i][1];
            if(!g(x,y)) continue;
            int newpos=3*x+y;

            swap(t[h.p],t[newpos]);
            int news=getnum();
            swap(t[h.p],t[newpos]);

            if(flag[news]==0||(flag[news]==1&&h.g+1<G[news]))
            {
                flag[news]=1; G[news]=h.g+1;
                path[news].from=h.s;
                path[news].dir=i;
                Q.push(Node(news,newpos,h.g+1,H(news)));
            }
        }
    }
}

int main()
{
  freopen("/home/wfgu/solve/data.in", "r", stdin);
    c[0]=1; for(int i=1;i<=8;i++) c[i]=c[i-1]*i;
    while(~scanf("%s",op))
    {
        read();
        int sum=0;
        for(int i=0;t[i];i++)
        {
            if(t[i]=='x') continue;
            for(int j=0;j<i;j++)
            {
                if(t[j]=='x') continue;
                if(t[i]<t[j]) sum++;
            }
        }

        if(sum%2==1)
        {
            printf("unsolvable\n");
            continue;
        }
        init();

        for(int i=0;i<9;i++)
            if(input[i]=='x'){A_star(getnum(),i); break; }
        while(!S.empty()){printf("%c",d[S.top()]); S.pop();}
        printf("\n");
    }
    return 0;
}
