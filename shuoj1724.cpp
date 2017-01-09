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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)

const int maxn=410;
int pic[25][25];
typedef pair<int,int> PII;
int m,n;
int sr,sc,er,ec;
int dr[]={2,1,-2,-1};
int dc[]={1,2,1,2};
bool inside(int r,int c){
    if(r<1||r>m||c<1||c>n)   return false;
    return true;
}
int bfs()
{
    memset(pic,-1,sizeof(pic));
    queue<pair<int,int> > q;
    q.push(MP(sr,sc));
    pic[sr][sc]=0;
    while(!q.empty()){
        PII cur = q.front();q.pop();
        int r = cur.first;
        int c = cur.second;
        if(r==er&&c==ec) break;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(inside(nr,nc)&&pic[nr][nc]==-1){
                q.push(MP(nr,nc));
                pic[nr][nc]=pic[r][c]+1;
            }
        }
    }
    return pic[er][ec];
}


int main()
{
    ios::sync_with_stdio(false);
    while(cin>>m>>n){
        memset(pic,0,sizeof(pic));
        cin>>sr>>sc>>er>>ec;
        if(sr==er&&sc==ec) {cout<<"0\n";continue;}

        
        if(bfs()==-1)    cout<<"Impossible"<<endl;
        else cout<<bfs()<<endl;
    }
    return 0;
}
