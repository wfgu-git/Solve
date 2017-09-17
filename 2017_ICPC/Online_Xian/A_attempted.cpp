/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, q, seed;
vector<vector<int> > G;

int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (cin >> n >> q) {
    G.resize(n + 2);
    G.clear();
    for (int i = 1; i < n; ++i) {
      static int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    cin >> seed;

    for (int i = 1; i <= n; ++i) {
      for (int p = 1; p < 64; ++p) {
        seed ^= seed * seed + 15;
        for (int q = 1; q <= 64; ++q) {
          M[i][p][q] = (seed >> (q - 1)) & 1;
        }
      }
    }
  }
  return 0;
}
