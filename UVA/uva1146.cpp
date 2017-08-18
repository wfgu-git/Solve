#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 20;
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
  void add_clause(int x, int xval, int y, int yval) {
    x = x * 2 + xval;
    y = y * 2 + yval;
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
int N;
int t[maxn][2];
bool check(int x) {
  tsat.init(N);
  for (int i = 0; i < N; ++i) for (int a = 0; a < 2; ++a) {
    for (int j = i + 1; j < N; ++j) for (int b = 0; b < 2; ++b) {
      if (abs(t[i][a] - t[j][b]) < x) {
          tsat.add_clause(i, a ^ 1, j, b ^ 1);
      }
    }
  }
  return tsat.run();
}
void work() {
  int L = 0, R = 0;
  for (int i = 0; i < N; ++i) for (int j = 0; j < 2; ++j) {
    scanf("%d", &t[i][j]);
    R = max(R, t[i][j]);
  }
  int ans = 0;
  while (L <= R) {
    int mid = (L + R) / 2;
    if (check(mid)) {
      ans = mid;
      L = mid + 1;
    } else {
      R = mid -  1;
    }
  }
  printf("%d\n", ans);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d", &N) != EOF && N) {
    work();
  }
  return 0;
}
