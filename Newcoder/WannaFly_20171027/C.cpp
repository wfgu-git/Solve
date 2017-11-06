/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<short, short> pss;

const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 20;

int n, m;
char grid[maxn][maxn];
short ld[maxn][maxn];
short dd[maxn][maxn];
short rd[maxn][maxn];
vector<pss> pl[maxn], pr[maxn];
bitset<maxn> bl[maxn], br[maxn];
void work() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j] != 'X') continue;
      ld[i][j] = ld[i + 1][j - 1] + 1;
      rd[i][j] = rd[i + 1][j + 1] + 1;
      dd[i][j] = dd[i + 1][j] + 1;

      pl[min(dd[i][j], rd[i][j])].push_back({i, j});
      pr[min(dd[i][j], ld[i][j])].push_back({i, j});
    }
  }

  for (int i = 1; i <= min(n, m); ++i) {
    for (pss & p : pl[i]) {
      bl[p.second][p.first] = 1;
    }
    for (pss & p : pr[i]) {
      br[p.second][p.first] = 1;
    }
  }

  int ans = 0;
  for (int i = 1, j = 0; i <= m; i += 2) {
    while (j < i) {
      for (pss & p : pl[j]) {
        bl[p.second][p.first] = 0;
      }
      for (pss & p : pr[j]) {
        br[p.second][p.first] = 0;
      }
      ++j;
    }
    for (int k = 1; k + i - 1 <= m; ++k) {
      if ((bl[k] & br[k + i - 1]).any()) {
        ans = i;
        break;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  freopen("data.in", "r", stdin);
  work();
}
