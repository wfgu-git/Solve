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
const int maxn=105;
char pic[maxn][maxn];
int n,m;
void dfs(int r,int c)
{
    if(r<0||r>=n||c<0||c>=m||pic[r][c]=='.')    return ;
    pic[r][c]='.';
    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1;dc<=1;dc++){
            if(dr!=0||dc!=0)
            dfs(r+dr,c+dc);
        }
    }
    return ;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)    scanf("%s",pic[i]);

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pic[i][j]=='W'){
                dfs(i,j);
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
