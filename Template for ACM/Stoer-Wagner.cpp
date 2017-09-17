/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <map>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 20;

int n, m;
int G[maxn][maxn];
int dist[maxn];
int vis[maxn];
int del[maxn];

int Stoer_Wagner() {
  int minCut = inf;
  int tmp;
  int pre;
  int s = 1;  // 源点
  memset(del, 0, sizeof(del));

  for (int T = 1; T < n; ++T) { // n - 1次最大生成树
    for (int i = 1; i <= n; ++i) if (!del[i]) {
      dist[i] = G[s][i];
    }
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    int t = s;
    for (int i = 1; i <= n - T; ++i) { // 每次剩下 n - T + 1 个结点
      tmp = -inf;
      pre = t;
      t = -1;
      for (int j = 1; j <= n; ++j) {
        if (!del[j] && !vis[j] && dist[j] > tmp) {
          t = j;
          tmp = dist[j];
        }
      }

      if (t == -1) return 0;  // 不连通

      vis[t] = 1;
      for (int j = 1; j <= n; ++j) {
        if (!del[j] && !vis[j]) {
          dist[j] += G[t][j];
        }
      }
    }

    minCut = min(minCut, dist[t]);
    del[t] = 1; // 删除t点

    // 合并t点和源点
    for (int i = 1; i <= n; ++i) {
      if (!del[i] && i != pre) {
        G[pre][i] += G[t][i];
        G[i][pre] = G[pre][i];
      }
    }
  }
  return minCut;
}
