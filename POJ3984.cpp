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
typedef pair<int,int> PII;
#define MP(a,b) make_pair(a,b)
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

int pic[5][5];
int dist[5][5];

bool inside(int r,int c)
{
    if(r<0||r>=5||c<0||c>=5)  return false;
    return true;
}

void print()
{
    vector<PII> ans;
    for(;;){
        ans.push_back(MP(0,0));
        if()
    }
}

int bfs()
{
    memset(dist,-1,sizeof(dist));
    queue<PII> q;
    q.push(MP(0,0));
    dist[0][0]=0;
    while(!q.empty()){
        PII cur=q.front();q.pop();
        int r=cur.first;
        int c=cur.second;
        if(r==4&&c==4) break;
        
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(inside(nr,nc)&&dist[nr][nc]==-1){
                dist[nr][nc]=dist[r][c]+1;
                q.push(MP(nr,nc));
            }
        }
    }
    return dist[4][4];
}
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>pic[i][j];
        }
    }    
    
    
    return 0;
}
