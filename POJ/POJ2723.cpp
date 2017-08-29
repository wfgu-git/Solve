/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 20;

struct TwoSAT {
  int n;
  vector<int> G[maxn * 2];
  int S[maxn * 2], c;
  bool mark[maxn * 2];
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n * 2; ++i) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }
  void add_clause(int x, int xval, int y, int yval) {
    x = x * 2 + xval;
    y = y * 2 + yval;
    G[x ^ 1].push_back(y);
    G[y ^ 1].push_back(x);
  }
  bool DFS(int x) {
    if (mark[x ^ 1]) return false;
    if (mark[x]) return true;
    S[c++] = x;
    mark[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
      if (!DFS(G[x][i])) return false;
    }
    return true;
  }
  bool run() {
    for (int i = 0; i < n * 2; i += 2) {
      if (!mark[i] && !mark[i + 1]) {
        c = 0;
        if (!DFS(i)) {
          while (c > 0) mark[S[--c]] = false;
          if (!DFS(i + 1)) return false;
        }
      }
    }
    return true;
  }
} tsat;
int N, M;
int keys[maxn][2];
int door[maxn][2];
void work() {
  tsat.init(N * 2);
  int x, y;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    tsat.add_clause(x, 1 ^ 1, y, 1 ^ 1);
  }
  for (int i = 0; i < M; ++i) {
    cin >> x >> y;
    door[i][0] = x;
    door[i][1] = y;
  }
  int ans = 0;
  for (ans = 0; ans < M; ++ans) {
    memset(tsat.mark, 0, sizeof(tsat.mark));
    tsat.add_clause(door[ans][0], 0 ^ 1, door[ans][1], 0 ^ 1);
    if (!tsat.run()) break;
  }
  cout << ans << endl;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> N >> M && N + M) {
    work();
  }
  return 0;
}
