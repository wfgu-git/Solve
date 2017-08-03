#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 50 + 5;
int grid[maxn][maxn];
int T, n, m;
double ans;
int main() {
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &grid[i][j]);
      }
    }

    printf("%.f\n", ans);
  }
  return 0;
}
