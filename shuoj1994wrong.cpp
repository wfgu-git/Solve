#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
#include<climits>
#include<queue>
#include<utility>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn=110;
struct Node{
    int x,y;
    int step;
    int mp;
    bool operator<(const Node &p)const {
        return step<p.step;
    }
};
Node start,target;
char pic[maxn][maxn];
bool vis[25][maxn][maxn];
//  mp r c
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m,s,c;

void init()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pic[i][j]=='S'){
                start.x=i;
                start.y=j;
            }
            if(pic[i][j]=='T'){
                target.x=i;
                target.y=j;
            }
        }
    }
}

bool legal(Node p)
{
    if(p.x<0||p.x>=n||p.y<0||p.y>=m||vis[p.mp][p.x][p.y])  return false;
    return true;
}

void bfs()
{
    mset(vis,0);
    init();
    start.step=0;
    start.mp=s;
    target.step=-1;
    priority_queue<Node> q;
    q.push(start);
    vis[start.mp][start.x][start.y]=true;

    while(!q.empty()){
        Node cur=q.top();
        q.pop();
        if(cur.x==target.x && cur.y==target.y){
            target.step=cur.step;
            return ;
        }

        for(int i=0;i<4;i++){
            Node nx;
            nx.x=cur.x+dx[i];
            nx.y=cur.y+dy[i];
            nx.step=cur.step+1;
            nx.mp= (cur.mp==s)?cur.mp:(cur.mp+1);
            
            if(legal(nx)){
                if(pic[nx.x][nx.y]=='T'){
                    target.step=nx.step;
                    return ;
                }
                if(pic[nx.x][nx.y]=='X')  
                    continue;
                else if(pic[nx.x][nx.y]=='D'){
                    if(nx.mp>=c){
                        nx.mp=nx.mp-c;
                        nx.step++;
                    } else {
                        nx.mp=1;
                        nx.step=nx.step+c-nx.mp+1;
                    }
                }
                q.push(nx);
                vis[nx.mp][nx.x][nx.y]=true;
            }
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        mset(pic,0);
        scanf("%d%d%d%d",&n,&m,&s,&c);
        for(int i=0;i<n;i++)  scanf("%s",pic+i);
        bfs();
        printf("%d\n",target.step);
    }
    return 0;
}
