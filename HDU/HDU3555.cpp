/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;
typedef __int64 ll;
const int maxn = 64 + 1;
const int inf = 0x3f3f3f3f;
__int64 dp[maxn][2];
int num[maxn];
__int64 N;
__int64 dfs(int pos, int pre, int state, bool limit) {
  if (pos == -1) return 1;
  if (!limit && dp[pos][state] != -1) return dp[pos][state];
  int up = (limit ? num[pos] : 9);
  ll tmp = 0;
  for (int i = 0; i <= up; ++i) {
    if (pre == 4 && i == 9) continue;
    tmp += dfs(pos - 1, i, i == 4, limit && i == num[pos]);
  }
  if (!limit) dp[pos][state] = tmp;
  return tmp;
}
void work() {
  memset(dp, -1, sizeof(dp));
  scanf("%I64d", &N);
  int pos = 0;
  __int64 tmp = N;
  while (tmp) {
    num[pos++] = tmp % 10;
    tmp /= 10;
  }
  __int64 ans = dfs(pos - 1, -1, 0, true);
  ans = N - ans + 1;
  printf("%I64d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
