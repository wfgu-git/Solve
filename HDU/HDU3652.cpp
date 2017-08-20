/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef __int64 ll;
const int inf = 0x3f3f3f3f;
const int maxn = 9 + 1;
int num[maxn];
int dp[maxn][10][13][2];
/*
dp[i][j][k][l]
i : pos
j : after % 13
k : has 13
l : lowestbit num
*/
int dfs(int pos, int pre, int rems, bool has, bool limit) {
  if (pos == -1) return !rems && has;
  if (!limit && dp[pos][pre][rems][has] != -1) return dp[pos][pre][rems][has];
  int up = (limit ? num[pos] : 9);
  int tmp = 0;
  for (int i = 0; i <= up; ++i) {
    tmp += dfs(pos - 1, i, (rems * 10 + i) % 13, has || (pre == 1 && i == 3), limit && i == num[pos]);
  }
  if (!limit) dp[pos][pre][rems][has] = tmp;
  return tmp;
}
int N;
void work() {
  int pos = 0;
  while (N) {
    num[pos++] = N % 10;
    N /= 10;
  }
  int ans = dfs(pos - 1, -1, 0, 0, true);
  printf("%d\n", ans);
}
int main() {
  // freopen("/home/wfgu/myset/solve/data.in", "r", stdin);
  memset(dp, -1, sizeof(dp));
  while (scanf("%d", &N) != EOF) {
    work();
  }
  return 0;
}
