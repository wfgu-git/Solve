/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 32 + 1;
int dp[maxn][2];
int num[maxn];
int lb, ub;
int dfs(int pos, int pre, int state, int limit) {
  if (pos == -1) return 1;
  if (!limit && dp[pos][state] != -1) return dp[pos][state];
  int up = (limit ? num[pos] : 9);
  int tmp = 0;
  for (int i = 0;  i <= up; ++i) {
    if (i == 4) continue;
    if (pre == 6 && i == 2) continue;
    tmp += dfs(pos - 1, i, i == 6, limit && i == num[pos]);
  }
  if (!limit) dp[pos][state] = tmp;
  return tmp;
}
void work() {
  memset(dp, -1, sizeof(dp));
  int l = lb - 1;
  int r = ub;
  int pos = 0;
  while (r) {
    num[pos++] = r % 10;
    r /= 10;
  }
  int ans = dfs(pos - 1, -1, 0, true);
  pos = 0;
  while (l) {
    num[pos++] = l % 10;
    l /= 10;
  }
  ans -= dfs(pos - 1, -1, 0, true);
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d%d", &lb, &ub) != EOF && (lb + ub)) {
    work();
  }
  return 0;
}
