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

// const int inf = numeric_limits<int>::max();
const int maxn = 100000 + 20;

struct TwoSAT {
  int n;
  vector<int> G[maxn * 2];
  bool mark[maxn * 2];
  int S[maxn * 2], c;

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

int N;
int s[maxn], t[maxn], d[maxn];
bool hit(int xs, int xe, int ys, int ye) {
  if (xe <= ys || ye <= xs) return false;
  return true;
}
int trans(char c) {return c - '0';}
void work() {
  tsat.init(N);
  string S, T;
  for (int i = 0; i < N; ++i) {
    cin >> S >> T >> d[i];
    S.erase(remove(S.begin(), S.end(), ':'), S.end());
    T.erase(remove(T.begin(), T.end(), ':'), T.end());
    s[i] = trans(S[0]) * 600 + trans(S[1]) * 60 + trans(S[2]) * 10 + trans(S[3]);
    t[i] = trans(T[0]) * 600 + trans(T[1]) * 60 + trans(T[2]) * 10 + trans(T[3]);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (hit(s[i], s[i] + d[i], s[j], s[j] + d[j])) {
        tsat.add_clause(i, 0 ^ 1, j, 0 ^ 1);
      }
      if (hit(s[i], s[i] + d[i], t[j] - d[j], t[j])) {
        tsat.add_clause(i, 0 ^ 1, j, 1 ^ 1);
      }
      if (hit(t[i] - d[i], t[i], s[j], s[j] + d[j])) {
        tsat.add_clause(i, 1 ^ 1, j, 0 ^ 1);
      }
      if (hit(t[i] - d[i], t[i], t[j] - d[j], t[j])) {
        tsat.add_clause(i, 1 ^ 1, j, 1 ^ 1);
      }
    }
  }
  if (tsat.run()) {
    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
      if (tsat.mark[2 * i]) {
        printf("%02d:%02d %02d:%02d\n", s[i] / 60, s[i] % 60, (s[i] + d[i]) / 60, (s[i] + d[i]) % 60);
      } else {
        printf("%02d:%02d %02d:%02d\n", (t[i] - d[i]) / 60, (t[i] - d[i]) % 60, t[i] / 60, t[i] % 60);
      }
    }
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  while (cin >> N) {
    work();
  }
  return 0;
}
