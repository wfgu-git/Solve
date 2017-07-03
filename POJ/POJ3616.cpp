#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxi = 1000;
const int maxn = 1e6;
struct info {
  int l, r, w;

  bool operator < (const info &rhs) const {
    if (l == rhs.l) {
      return r < rhs.r;
    }
    return l < rhs.l;
  }
  info() {}
  info(int _l, int _r, int _w) : l(_l), r(_r), w(_w) {}
} w[maxi + 2];
int dp[maxn + 2];

int main() {
  int n, m, rest;
  while (scanf("%d%d%d", &n, &m, &rest) == 3) {
    for (int i = 1; i <= m; i++) {
      int l, r, val;
      scanf("%d%d%d", &l, &r, &val);
      w[i] = info(l, r, val);
    }

    sort(w + 1, w + 1 + m);
    // memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) dp[i] = w[i].w;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= i; j++) {
        if (w[j].r + rest <= w[i].l) {
          dp[i] = max(dp[i], dp[j] + w[i].w);
        }
      }
    }
    int ans = -1e9;
    for (int i = 1; i <= m; i++) {
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
