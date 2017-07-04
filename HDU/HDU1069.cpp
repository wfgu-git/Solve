#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct Rectangular {
  int x, y, z;
  void init() {
    if (x > y) swap(x, y);
  }
  bool operator < (const Rectangular &rhs) const {
    if (x != rhs.x) return x < rhs.x;
    return y < rhs.y;
  }
} rec[30 * 3 + 2];
int tot;
void add_rec(int x, int y, int z) {
  rec[++tot].x = x, rec[tot].y = y, rec[tot].z = z;
  rec[++tot].x = y, rec[tot].y = z, rec[tot].z = x;
  rec[++tot].x = x, rec[tot].y = z, rec[tot].z = y;
}
int dp[30 * 3 + 2];
int main() {
  int n;
  int kase = 0;
  while (scanf("%d", &n) == 1 && n) {
    tot = 0;
    for (int i = 0; i < n; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      add_rec(x, y, z);
    }
    for (int i = 1; i <= tot; i++) {
      rec[i].init();
    }
    sort(rec + 1, rec + 1 + tot);
    for (int i = 1; i <= tot; i++) {
      dp[i] = rec[i].z;
    }
    for (int i = 1; i <= tot; i++) {
      int maxh = -inf;
      for (int j = 1; j < i; j++) {
        if (rec[j].x < rec[i].x && rec[j].y < rec[i].y) {
          maxh = max(maxh, dp[j]);
        }
        dp[i] = max(dp[i], maxh + rec[i].z);
      }
    }
    int ans = -inf;
    for (int i = 1; i <= tot; i++) {
      ans = max(ans, dp[i]);
    }
    printf("Case %d: maximum height = %d\n", ++kase, ans);
  }
  return 0;
}
