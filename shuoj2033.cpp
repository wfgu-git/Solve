#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
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
const int maxn=10010;
int x,target;
bool prime[maxn];
int dis[maxn];
bool vis[maxn];
void Primetab()
{
    for(int i=1000;i<10000;i++){
        prime[i]=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i % j == 0){
            prime[i]=false;
            break;
            }
        }
    }
}

bool IsEven(int x)
{
    return x % 2 == 0;
}

int change(int x,int pos,int k)
{
    int res;
    if(pos==0){
        res=x % 1000;
        res=res+k*1000;
    }
    else if(pos==1){
        res=(x/1000)*1000;
        res=res+x%100;
        res=res+k*100;
    }
    else if(pos==2){
        res=(x/100)*100;
        res=res+x%10;
        res=res+k*10;
    }
    else{
        res=(x/10)*10;
        res=res+k;
    }
    return res;
}

void bfs()
{
    MEM(dis,-1);
    queue<int> q;
    q.push(x);
    dis[x]=0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur==target) return ; // if x == target
        for(int pos=0;pos<4;pos++){
            for(int i=0;i<10;i++){
                if(pos==0&&i==0) continue;
                int nx=change(cur,pos,i);
                if(IsEven(nx) || !prime[nx]) continue;
                if(dis[nx]==-1){
                    dis[nx]=dis[cur]+1;
                    vis[nx]=true;
                    if(nx==target) return ;
                    q.push(nx);
                }
            }
        }    
    }
}

int main()
{
    int t;
    cin >> t;
    Primetab();
    while(t--){
        cin >> x >> target;
        bfs();
        cout<<dis[target]<<endl;
    }
    return 0;
}
