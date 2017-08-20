/*
Life has never been fucking so easy...
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 8000 + 20;
struct TwoSAT {
  int n;
  vector<int> G[maxn * 2];
  bool mark[maxn * 2];
  int S[maxn * 2], c;

  bool dfs(int x) {
    if (mark[x ^ 1]) return false;
    if (mark[x]) return true;
    mark[x] = true;
    S[c++] = x;
    for (int i = 0; i < G[x].size(); ++i) {
      if (!dfs(G[x][i])) return false;
    }
    return true;
  }

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n * 2; ++i) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }

  // x = xval or y = yval
  void add_clause(int x, int y) {
    // x = x * 2 + xval;
    // y = y * 2 + yval;
    // G[x ^ 1].push_back(y);
    // G[y ^ 1].push_back(x);
    G[x ^ 1].push_back(y);
    G[y ^ 1].push_back(x);
  }

  bool run() {
    for (int i = 0; i < n * 2; i += 2) {
      if (!mark[i] && !mark[i + 1]) {
        c = 0;
        if (!dfs(i)) {
          while (c > 0) mark[S[--c]] = false;
          if (!dfs(i + 1)) return false;
        }
      }
    }
    return true;
  }
} tsat;
int N, M;
void work() {
  tsat.init(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    tsat.add_clause((u - 1) ^ 1, (v - 1) ^ 1);
  }
  if (!tsat.run()) {
    printf("NIE\n");
  } else {
    for (int i = 1; i < N * 2; i += 2) {
      if (tsat.mark[i - 1]) printf("%d\n", i);
      else printf("%d\n", i + 1);
    }
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
}
