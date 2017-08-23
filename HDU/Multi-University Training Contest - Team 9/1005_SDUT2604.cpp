#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#define MAX 1000
#define inf 0x3f3f3f3f
using namespace std;
struct node {
  int to, next;
} q[1000000];

int head[10100], cnt;
bool vis[2100], mp[2100][2100];
void add(int a, int b) {
  q[cnt].to = b;
  q[cnt].next = head[a];
  head[a] = cnt++;
}

void bfs(int x) {
  memset(vis, false, sizeof(vis));
  queue<int> qu;
  qu.push(x);
  vis[x] = true;
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    for (int i = head[u]; ~i; i = q[i].next) {
      int v = q[i].to;
      if (vis[v]) continue;
      mp[x][v] = true;
      qu.push(v);
      vis[v] = true;
    }
  }
}

int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/solve/true_data.out", "w", stdout);
  int n, m, i, j, k, cla, a, b;
  while (~scanf("%d", &cla)) {
    for (int zu = 1; zu <= cla; ++zu) {
      scanf("%d%d", &n, &m);
      cnt = 0;
      memset(head, -1, sizeof(head));
      memset(mp, false, sizeof(mp));

      for (i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b);
      }
      for (i = 1; i <= n; ++i) bfs(i);
      bool bj = false;
      for (i = 1; i <= n; ++i) {
        for (j = i + 1; j <= n; ++j) {
          if (!mp[i][j] && !mp[j][i]) {
            bj = true;
            break;
          }
        }
        if (bj) break;
      }
      if (bj)
        puts("Light my fire!");
      else
        puts("I love you my love and our love save us!");
    }
  }
  return 0;
}
