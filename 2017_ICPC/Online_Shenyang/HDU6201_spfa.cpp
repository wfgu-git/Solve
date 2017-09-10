/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

vector<pii> G[maxn];
int d[maxn];
int inq[maxn];
void SPFA(int s, int n) {
  fill(d, d + 2 * n + 5, -inf);
  memset(inq, 0, sizeof(inq));
  inq[s] = 1; d[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    inq[u] = 0;
    for (pii x : G[u]) {
      int v = x.first;
      int w = x.second;
      if (d[v] < d[u] + w) {
        d[v] = d[u] + w;
        if (!inq[v]) {
          inq[v] = 1;
          Q.push(v);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    cin >> n;
    for (int i = 0; i <= 2 * n + 5; ++i) {
      G[i].clear();
    }
    int s = 0;
    int t = 2 * n + 2;
    for (int i = 1; i <= n; ++i) {
      int tmp;
      cin >> tmp;
      G[s].push_back({2 * i, -tmp});
      G[2 * i + 1].push_back({t, tmp});
      G[2 * i].push_back({2 * i + 1, 0});
    }
    int u, v, w;
    for (int i = 1; i < n; ++i) {
      cin >> u >> v >> w;
      G[2 * u + 1].push_back({2 * v, -w});
      G[2 * v + 1].push_back({2 * u, -w});
    }
    SPFA(s, n);
    cout << d[t] << endl;
  }
}
