#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
struct Max_Match
{
  int n;
  bool g[maxn][maxn];
  bool vis[maxn];
  int left[maxn];

  void init(int n) {
    this->n = n;
    memset(g, 0, sizeof(g));
    memset(left, -1, sizeof(left));
   }

  bool dfs(int u) {
    for(int v = 1; v <= n; v++)if(g[u][v] && !vis[v]) {
      vis[v]=true;
      if(left[v] == -1 || dfs(left[v])) {
        left[v] = u;
        return true;
      }
    }
    return false;
  }

  int solve() {
    int ans=0;
    for(int i = 1; i <= n; i++) {
      memset(vis,0,sizeof(vis));
      if(dfs(i)) ++ans;
    }
    return ans;
  }
} MM;
int main() {

  return 0;
}
