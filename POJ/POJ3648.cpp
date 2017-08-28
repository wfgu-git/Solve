/*
   教练我要打ACM!
   Life has never been fucking so easy...
*/
#include <iostream>
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
  /*
    2i --> wife
    2i + 1 --> husband
    0 -->
    1 -->
  */

  int x, y;
  char dx, dy;
  tsat.init(N * 2);
  for (int i = 0; i < M; ++i) {
    scanf("%d%c %d%c", &x, &dx, &y, &dy);
    x = 2 * x + hus(dx);
    y = 2 * y + hus(dy);

  }
  for (int i = 1; i < N; ++i) {
  }
  if (tsat.run()) {
    for (int i = 2; i < 2 * N; i += 2) {
      if (tsat.mark[]) {
        printf("%dw", i / 2);
      } else {
        printf("%dh", i / 2);
      }
      printf("%s", i < 2 * N - 2 ? " " : "\n");
    }
  } else {
    puts("bad luck");
  }
}
int main() {
  while (scanf("%d%d", &N, &M) != EOF && N + M) {
    work();
  }
  return 0;
}
