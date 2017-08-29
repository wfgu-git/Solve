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
int N, A, B;
int Sx[2], Sy[2];
int X[maxn], Y[maxn];
int hate[maxn][2], like[maxn][2];
int dist[maxn][2], Sd;
inline int Getdist(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
bool check(int x) {
  tsat.init(N);
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (dist[i][k] + dist[j][k] > x) {
          tsat.add_clause(i, k ^ 1, j, k ^ 1);
        }
        if (dist[i][k] + dist[j][1 - k] + Sd > x) {
          tsat.add_clause(i, k ^ 1, j, (1 - k) ^ 1);
        }
      }
    }
  }

  for (int i = 0; i < A; ++i) {
    for (int k = 0; k < 2; ++k) {
      tsat.add_clause(hate[i][0], k ^ 1, hate[i][1], k ^ 1);
      tsat.add_clause(hate[i][0], (1 - k) ^ 1, hate[i][1], (1 - k) ^ 1);
    }
  }
  for (int i = 0; i < B; ++i) {
    for (int k = 0; k < 2; ++k) {
      tsat.add_clause(like[i][0], k ^ 1, like[i][1], (1 - k) ^ 1);
      tsat.add_clause(like[i][0], (1 - k) ^ 1, like[i][1], k ^ 1);
    }
  }
  return tsat.run();
}
void work() {
  for (int i = 0; i < 2; ++i) {
    cin >> Sx[i] >> Sy[i];
  }
  Sd = Getdist(Sx[0], Sy[0], Sx[1], Sy[1]);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  for (int i = 0; i < A; ++i) {
    cin >> hate[i][0] >> hate[i][1];
    --hate[i][0]; --hate[i][1];
  }
  for (int i = 0; i < B; ++i) {
    cin >> like[i][0] >> like[i][1];
    --like[i][0]; --like[i][1];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 2; ++j) {
      dist[i][j] = Getdist(X[i], Y[i], Sx[j], Sy[j]);
    }
  }
  int lb = 0, ub = 10000000;
  int ans = -1;
  while (lb <= ub) {
    int mid = (lb + ub) / 2;
    if (check(mid)) {
      ans = mid;
      ub = mid - 1;
    } else {
      lb = mid + 1;
    }
  }
  cout << ans << endl;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> N >> A >> B) {
    work();
  }
  return 0;
}
