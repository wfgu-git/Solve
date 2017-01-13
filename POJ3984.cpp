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
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

bool vis[5][5];
int pic[5][5];
PII pre[5][5];
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};


bool inside(int r,int c)
{
    return !(r<0||r>=5||c<0||c>=5);
}


void bfs()
{
    MEM(vis,false);
    queue<PII> q;
    q.push(MP(0,0));
    vis[0][0]=true;
    
    while(!q.empty()){
        PII cur=q.front();q.pop();
        int r=cur.fi;
        int c=cur.se;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(!vis[nr][nc]&&inside(nr,nc)&&pic[nr][nc]==0){
                vis[nr][nc]=true;
                q.push(MP(nr,nc));
                pre[nr][nc]=MP(r,c);
                if(nr==4&&nc==4) break;
            }
        }
    }

}
//dfs 打印路径
void print_path(int r,int c)
{
    if(r==0&&c==0){
        cout<<"("<<r<<", "<<c<<")\n";
        return ;
    }
    print_path(pre[r][c].fi,pre[r][c].se);
    cout<<"("<<r<<", "<<c<<")\n";
}

int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>pic[i][j];
        }
    }

    bfs();
    print_path(4,4);
    return 0;
}
