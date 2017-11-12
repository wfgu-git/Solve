/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 500 + 20;

char grid[maxn][maxn];
int ldx[maxn][maxn];
int ldo[maxn][maxn];
int ddx[maxn][maxn];
int ddo[maxn][maxn];
int rdx[maxn][maxn];
int rdo[maxn][maxn];
void BFS(int x, int y) {
  queue<int> Q;

}
void work() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'X') ans = 1;
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j] == 'X') {
        ldx[i][j] = ldx[i + 1][j - 1] + 1;
        rdx[i][j] = rdx[i + 1][j - 1] + 1;
        ddx[i][j] = ddx[i + 1][j] + 1;
        int t = 1;
        while (true) {
          if (i - t <= 0 || j + t > m) break;
          if (grid[i - t][j + t] != 'O') break;
          ldo[i][j] = t;
          t++;
        }
        t = 1;
        while (true) {
          if (i + t > n || j + t > m) break;
          if (grid[i + t][j + t] != 'O') break;
          rdo[i][j] = t;
          t++;
        }
      } else {
        ddo[i][j] = ddo[i + 1][j] + 1;
      }
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     cout << rdx[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for (int l = 500; l >= 1; --l) {
    for (int i = 1; i <= n; ++i) {
      if (i - l / 2 <= 0 || i + l / 2 > n) continue;
      for (int j = 1; j <= m; ++j) {
        if (j - l / 2 <= 0 || j + l / 2 > m) continue;
        if (grid[i][j] != 'X') continue;
        // if (i == 3 && j == 3) {
        //   cout << ldx[i][j] << " ";
        //   cout << rdx[i][j] << " ";
        //   cout << ddx[i - l / 2][j - l / 2] << " ";
        //   cout << ldo[i][j] << " ";
        //   cout << rdo[i][j] << " ";
        //   cout << ddo[i + l / 2][j + l / 2] << " ";
        // }
        // cout << endl;
        if (ldx[i][j] >= l / 2 && rdx[i][j] >= l / 2 && ddx[i - l / 2][j - l / 2] >= l
          && ldo[i][j] >= l / 2 && rdo[i][j] >= l / 2 && ddo[i - l / 2][j + l / 2] >= l) {
            ans = l;
            goto out;
          }
      }
    }
  }
  out: ;
  cout << ans << endl;
}
int main() {
  freopen("data.in", "r", stdin);
  work();
}
