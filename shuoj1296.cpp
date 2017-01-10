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
int fa[5050];
void init(int n)
{
    for(int i=0;i<=n;i++)    fa[i]=i;
}

int find(int x)
{
    if(x!=fa[x])    fa[x]=find(fa[x]);
    return fa[x];
}

void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return ;
    fa[a]=b;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m,p;
    while(cin>>n>>m>>p){
        init(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            merge(a,b);
        }

        while(p--){
            int a,b;
            cin>>a>>b;
            if(find(a)==find(b))   cout<<"Yes"<<endl;
            else    cout<<"No"<<endl;
        }
    }
    return 0;
}
