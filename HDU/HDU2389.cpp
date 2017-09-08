/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 20;

int t, n, m;
int mep[maxn][maxn];
int cx[maxn];
int cy[maxn];
int dx[maxn];
int dy[maxn];
int dist;
bool mark[maxn];
bool BFS() {
  dist = inf;
  memset(dx, -1, sizeof(dx));
  memset(dy, -1, sizeof(dy));
  queue<int> Q;
  for (int i = 0; i < m; ++i) {
    if (cx[i] == -1) {
      Q.push(i);
      dx[i] = 0;
    }
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (dx[u] > dist) break;
    for (int v = 0; v < n; ++v) {
      if (mep[u][v] && dy[v] == -1) {
        dy[v] = dx[u] + 1;
        if (cy[v] == -1) {
          dist = dy[v];
        } else {
          dx[cy[v]] = dy[v] + 1;
          Q.push(cy[v]);
        }
      }
    }
  }
  return dist != inf;
}
int DFS(int u) {
  for (int v = 0; v < n; ++v) {
    if (!mark[v] && mep[u][v] && dy[v] == dx[u] + 1) {
      mark[v] = 1;
      if (cy[v] != -1 && dy[v] == dist) {
        continue;
      }
      if (cy[v] == -1 || DFS(cy[v])) {
        cy[v] = u;
        cx[u] = v;
        return 1;
      }
    }
  }
  return 0;
}
int run() {
  int ret = 0;
  memset(cx, -1, sizeof(cx));
  memset(cy, -1, sizeof(cy));
  while (BFS()) {
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < m; ++i) {
      if (cx[i] == -1) {
        ret += DFS(i);
      }
    }
  }
  return ret;
}
int x[maxn], y[maxn], velo[maxn];
void add_edge(int j, int tx, int ty) {
  double d;
  for (int i = 0; i < m; ++i) {
    d = hypot(tx - x[i], ty - y[i]);
    if (1.0 * velo[i] * t >= d) {
      mep[i][j] = 1;
    }
  }
}
int main() {
  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> t >> m;
    for (int i = 0; i < m; ++i) {
      cin >> x[i] >> y[i] >> velo[i];
    }
    cin >> n;
    int tx, ty;
    memset(mep, 0, sizeof(mep));
    for (int i = 0; i < n; ++i) {
      cin >> tx >> ty;
      add_edge(i, tx, ty);
    }
    cout << "Scenario #" << cas << ":\n";
    cout << run() << "\n" << endl;
  }
}
