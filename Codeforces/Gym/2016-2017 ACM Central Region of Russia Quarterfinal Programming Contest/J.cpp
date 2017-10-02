/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

struct info {
  int x, y;
  int val;
} ;
info tickets[2][maxn];
struct Max_Match {
  int n, m;
  bool g[maxn][maxn];
  bool vis[maxn];
  int left[maxn];

  void init(int n, int m) {
    this->n = n;
    this->m = m;
    memset(g, 0, sizeof(g));
    memset(left, -1, sizeof(left));
  }

  bool dfs(int u) {
    for (int v = 0; v < m; ++v) if (g[u][v] && !vis[v]) {
      vis[v] = true;
      if (left[v] == -1 || dfs(left[v])) {
        left[v] = u;
        return true;
      }
    }
    return false;
  }
  int solve() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      memset(vis, 0, sizeof(vis));
      if (dfs(i)) ++ans;
    }
    return ans;
  }
} MM;
int n, m;
void init(int x, int t, int id) {
  int ori = x;
  int last = 0;
  for (int i = 0; i < 3; ++i) {
    last += x % 10;
    x /= 10;
  }
  int pre = 0;
  for (int i = 0; i < 3; ++i) {
    pre += x % 10;
    x /= 10;
  }
  tickets[t][id] = {pre, last, ori};
}
int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> m) {
    int x;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      init(x, 0, i);
    }
    for (int i = 0; i < m; ++i) {
      cin >> x;
      init(x, 1, i);
    }
    MM.init(n, m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (tickets[0][i].x == tickets[1][j].y || tickets[0][i].y == tickets[1][j].x) {
          MM.g[i][j] = 1;
        }
      }
    }

    int ans = MM.solve();
    cout << ans << endl;
    for (int i = 0; i < m; ++i) {
      if (MM.left[i] != -1) {
        int T = i;
        int A = MM.left[i];
        if (tickets[0][A].x == tickets[1][T].y) {
          cout << "AT " << tickets[0][A].val << " " << tickets[1][T].val << endl;
        } else {
          cout << "TA " << tickets[1][T].val << " " << tickets[0][A].val << endl;
        }
      }
    }
  }
}
