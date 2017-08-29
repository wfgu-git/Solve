/*
   教练我要打ACM!
   Life has never been fucking so easy...
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 20;
int N, M;
inline int hus(const char& x) {return x == 'h';}
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
void work() {
  tsat.init(N);
  /*
  xval = 0 --> x husband opposite 0 (x * 2)
  xval = 1 --> x wife opposite 0 (x * 2 + 1)
  */
  int x, y;
  char dx[2], dy[2];
  tsat.add_clause(0, 1 ^ 1, 0, 1 ^ 1);
  for (int i = 0; i < M; ++i) {
    scanf("%d%s %d%s", &x, dx, &y, dy);
    if (dx[0] == 'h' && dy[0] == 'h') {
      tsat.add_clause(x, 0 ^ 1, y, 0 ^ 1);
    }
    if (dx[0] == 'h' && dy[0] == 'w') {
      tsat.add_clause(x, 0 ^ 1, y, 1 ^ 1);
    }
    if (dx[0] == 'w' && dy[0] == 'h') {
      tsat.add_clause(x, 1 ^ 1, y, 0 ^ 1);
    }
    if (dx[0] == 'w' && dy[0] == 'w') {
      tsat.add_clause(x, 1 ^ 1, y, 1 ^ 1);
    }
  }
  if (tsat.run()) {
    for (int i = 1; i < N; ++i) {
      if (tsat.mark[i * 2]) {
        printf("%dw", i);
      } else {
        printf("%dh", i);
      }
      printf("%s", i <  N - 1 ? " " : "\n");
    }
  } else {
    puts("bad luck");
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF && N + M) {
    work();
  }
  return 0;
}
