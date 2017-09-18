/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
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
  int ideg[maxn];
  int odeg[maxn];
  void init(int n) {
    this->n = n;
    edges.clear();
    for (int i = 0; i < n; ++i) {
      G[i].clear();
      rG[i].clear();
      // nG[i].clear();
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
    memset(ideg, 0, sizeof(ideg));
    memset(odeg, 0, sizeof(odeg));
    map<pair<int, int>, bool> S;
    S.clear();
    for (int i = 0; i < edges.size(); ++i) {
      int u = sccno[edges[i].first];
      int v = sccno[edges[i].second];
      if (u != v) {
        if (S.count(make_pair(u, v))) continue;
        S[make_pair(u, v)] = 1; // 无向图双边
        ++odeg[u]; ++ideg[v];
        // nG[u].push_back(v);
      }
    }
  }
} scc;

void work() {
  int N, M;
  cin >> N >> M;
  scc.init(N);
  int u, v;
  for (int i = 0; i < M; ++i) {
    cin >> u >> v;
    scc.add_edge(u - 1, v - 1);
  }
  scc.run();
  if (scc.scc_tot == 1) {
    cout << "0" << endl;
    return;
  }
  int ans1 = 0;
  int ans2 = 0;
  for (int i = 0; i < scc.scc_tot; ++i) {
    if (!scc.ideg[i]) ++ans1;
    if (!scc.odeg[i]) ++ans2;
  }
  cout << max(ans1, ans2) << endl;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    work();
  }
}
