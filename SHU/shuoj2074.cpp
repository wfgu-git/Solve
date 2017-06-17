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
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pt(a) printf("%d\n",a)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 10;
int T;
char pic[maxn][maxn];

bool inside(int r, int c)
{
    if(r<0||r>=9||c<0||c>=9)  return false;
    return true;
}

int dx[]={-1,1,0,0,-1,1,1,-1};
int dy[]={0,0,-1,1,-1,-1,1,1};
bool mark;
void dfs(int dir, int x, int y, int num, bool used)
{
    if(num == 5 && used)  {
        mark = true;
        return ;
    }
    int nx,ny;
    nx = x + dx[dir];
    ny = y + dy[dir];
    if(!inside(nx,ny))  return ;
    if(pic[nx][ny] == 'B' || pic[nx][ny] == 'O'){
        if(pic[nx][ny] == 'B'){
            dfs(dir,nx,ny,num+1,used); 
        }else {
            if(used == false){
                dfs(dir,nx,ny,num+1,used=true);
            } else{
                return ;
            }
        }
    }
    else return ;
}

int main(void)
{
    sc(T);
    while(T--){
        mark = false;
        for(int i=0; i<9; i++){
            scanf("%s",pic+i);
        }

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(pic[i][j] == 'B'){
                    for(int k=0; k<8; k++){
                        int num = 1;
                        bool used = false;
                        dfs(k,i,j,num,used);
                    } 
                }
            }
        }

        if(mark)  printf("Yes!\n");
        else  printf("No!\n");
    }
    return 0;
}
