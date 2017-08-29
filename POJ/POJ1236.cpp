/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

struct DAG {
  int n;
  vector<int> G[maxn];
  vector<int> rG[maxn];
  vector<int> nG[maxn];
  vector<int> vs;
  vector<pair<int, int> > edges;
  bool used[maxn];
  int sccno[maxn], scc_tot;
  vector<int> ideg, odeg;
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i) {
      G[i].clear();
      rG[i].clear();
      nG[i].clear();
    }
  }
  void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
    edges.push_back({from, to});
  }
  void DFS(int x) {
    used[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
      if (!used[G[x][i]]) DFS(G[x][i]);
    }
    vs.push_back(x);
  }
  void rDFS(int x, int k) {
    used[x] = true;
    sccno[x] = k;
    for (int i = 0; i < rG[x].size(); ++i) {
      if (!used[rG[x][i]]) rDFS(rG[x][i], k);
    }
  }
  void scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int v = 0; v < n; ++v) {
      if (!used[v]) DFS(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for (vector<int>::reverse_iterator it = vs.rbegin(); it != vs.rend(); ++it){
      if (!used[*it]) rDFS(*it, k++);
    }
    scc_tot = k;
  }
  void run() {
    scc();
    ideg.resize(scc_tot);
    odeg.resize(scc_tot);
    map<pair<int, int>, bool> S;
    for (int i = 0; i < edges.size(); ++i) {
      int u = sccno[edges[i].first];
      int v = sccno[edges[i].second];
      if (u != v) {
        if (S.count(make_pair(u, v))) continue;
        S[make_pair(u, v)] = 1; // 无向图双边
        ++odeg[u]; ++ideg[v];
        nG[u].push_back(v);
      }
    }
  }
} scc;

int N;
void work() {
  scc.init(N);
  for (int i = 0; i < N; ++i) {
    int x;
    while (cin >> x && x) {
      --x; scc.add_edge(i, x);
    }
  }
  scc.run();
  if (scc.scc_tot == 1) {
    cout << "1\n0" << endl;
    return;
  }
  int tot = 0;
  int tmp = 0;
  for (int i = 0; i < scc.scc_tot; ++i) {
    if (!scc.ideg[i]) ++tot;
    if (!scc.odeg[i]) ++tmp;
  }
  cout << tot << "\n" << max(tot, tmp) << endl;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (cin >> N) {
    work();
  }
}
