/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

struct TwoSAT {
  int n;
  vector<int> G[maxn * 2];
  bool mark[maxn * 2];
  int S[maxn * 2], c;
  void init(int n) {
    this->n = n;
    for (int i = 0; i < 2 * n; ++i) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }
  bool DFS(int x) {
    if (mark[x ^ 1]) return false;
    if (mark[x]) return true;
    mark[x] = true;
    S[c++] = x;
    for (int i = 0; i < G[x].size(); ++i) {
      if (!DFS(G[x][i])) return false;
    }
    return true;
  }
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
void work() {
  tsat.init(N);
  string op;
  int x, y, v;
  for (int i = 0; i < M; ++i) {
    cin >> x >> y >> v >> op;
    if (op[0] == 'A') {
      if (v) {
        tsat.add_clause(x, 1 ^ 1, y, 0 ^ 1);
        tsat.add_clause(x, 0 ^ 1, y, 1 ^ 1);
        tsat.add_clause(x, 0 ^ 1, y, 0 ^ 1);
      } else {
        tsat.add_clause(x, 1 ^ 1, y, 1 ^ 1);
      }
    } else if (op[0] == 'O') {
      if (v) {
        tsat.add_clause(x, 0 ^ 1, y, 0 ^ 1);
      } else {
        tsat.add_clause(x, 1 ^ 1, y, 0 ^ 1);
        tsat.add_clause(x, 0 ^ 1, y, 1 ^ 1);
        tsat.add_clause(x, 1 ^ 1, y, 1 ^ 1);
      }
    } else {
      if (v) {
        tsat.add_clause(x, 1 ^ 1, y, 1 ^ 1);
        tsat.add_clause(x, 0 ^ 1, y, 0 ^ 1);
      } else {
        tsat.add_clause(x, 1 ^ 1, y, 0 ^ 1);
        tsat.add_clause(x, 0 ^ 1, y, 1 ^ 1);
      }
    }
  }
  if (tsat.run()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> N >> M) {
    work();
  }
  return 0;
}
