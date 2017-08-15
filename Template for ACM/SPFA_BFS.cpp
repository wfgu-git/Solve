#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

const int maxn = 10005;
bool vis[maxn];
int dis[maxn];
int ecnt;
vector<int> G[maxn];
const int inf = 0x3f3f3f3f;
struct Edge {int from, to, cost;} edge[maxn * maxn];
void addedge(int u, int v, int w) {
  edge[ecnt] = {u, v, w};
  G[u].push_back(ecnt++);
}
void spfa(int s) {
  queue<int> q;
  memset(vis, 0, sizeof(vis));
  q.push(s);
  dis[s] = 0;
  vis[s] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    vis[cur] = false;
    for (int i = 0; i < G[cur].size(); i++) {
      Edge &e = edge[G[cur][i]];
      if (dis[e.to] > dis[e.from] + e.cost) {
        dis[e.to] = dis[e.from] + e.cost;
        if (!vis[e.to]) {
          q.push(e.to);
        }
      }
    }
  }
}
void init(int n) {
  ecnt = 0;
  memset(dis, inf, sizeof(dis));
  for(int i = 0; i < n; i++) {
    G[i].clear();
  }
}
