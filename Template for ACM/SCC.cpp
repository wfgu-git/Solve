#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 20;

int n;
vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> nG[maxn];
vector< pair< int, int > > edges;
vector<int> vs;
bool vis[maxn];
int sccno[maxn], scc_tot;
int ideg[maxn], odeg[maxn];

void init() {
  for (int i = 0; i < n; ++i) {
    G[i].clear();
    rG[i].clear();
    nG[i].clear();
  }
  edges.clear();
}
void add_edge(int from, int to) {
  G[from].push_back(to);
  rG[to].push_back(from);
  edges.push_back({from, to});
}
void DFS(int x) {
  vis[x] = true;
  for (int i = 0; i < G[x].size(); ++i) {
    if (!vis[G[x][i]]) DFS(G[x][i]);
  }
  vs.push_back(x);
}
void rDFS(int x, int k) {
  vis[x] = true;
  sccno[x] = k;
  for (int i = 0; i < rG[x].size(); ++i) {
    if (!vis[rG[x][i]]) rDFS(rG[x][i], k);
  }
}
void scc() {
  memset(vis, 0, sizeof(vis));
  vs.clear();
  for (int v = 0; v < n; ++v) {
    if (!vis[v]) DFS(v);
  }
  memset(vis, 0, sizeof(vis));
  int k = 0;
  for (vector<int>::reverse_iterator it = vs.rbegin(); it != vs.rend(); ++it){
    if (!vis[*it]) rDFS(*it, k++);
  }
  scc_tot = k;
}
void run() {
  memset(ideg, 0, sizeof(ideg));
  memset(odeg, 0, sizeof(odeg));
  // map 去重看情况
  map< pair< int, int >, bool > S;
  for (int i = 0; i < edges.size(); ++i) {
    int u = sccno[edges[i].first];
    int v = sccno[edges[i].second];
    if (u != v) {
      if (S.count(make_pair(u, v))) continue;
      S[make_pair(u, v)] = 1;
      ++odeg[u]; ++ideg[v];
      nG[u].push_back(v);
    }
  }
}
