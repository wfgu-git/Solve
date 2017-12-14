/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 70 + 20;
const int maxk = 100 + 20;

int n, k;
ll dp[maxn][maxn];
int limit[maxk][3];
bool check_help(int x, int y, int l, int r) {
/*
< 0  <= 1
= 2
>= 3  > 4
*/
  for (int i = 0; i < k; ++i) {
    const int & a = limit[i][0];
    const int & b = limit[i][2];
    const int & op = limit[i][1];
    if ((a == x && b == y) || (a == y && b == x)) {
      if (op == 0 || op == 4) {
        return false;
      }
    } else if (a == x || a == y) {
      if (b >= l && b <= r) {
        if (op >= 2) {
          return false;
        }
      }
    } else if (b == x || b == y) {
      if (a >= l && a <= r) {
        if (op <= 2) {
          return false;
        }
      }
    }
  }
  return true;
}
bool check(int x, int y, int l, int r) {
  int p = check_help(x, y, l, r);
  int q = check_help(x, y, l, r);
  return p && q;
}
void work() {
  scanf("%d%d", &n, &k);
  char buf[3];
/*
< 0  <= 1
= 2
>= 3  > 4
*/
  for (int i = 0; i < k; ++i) {
    memset(buf, 0, sizeof(buf));
    scanf("%d%s%d", &limit[i][0], buf, &limit[i][2]);
    if (buf[0] == '=') {
      limit[i][1] = 2;
    } else if (buf[0] == '<') {
      if (buf[1] == '=') limit[i][1] = 1;
      else limit[i][1] = 0;
    } else if (buf[0] == '>'){
      if (buf[1] == '=') limit[i][1] = 3;
      else limit[i][1] = 4;
    }
  }

  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < 2 * n; ++i) {
    if (check(i, i + 1, 0, 0)) dp[i][i + 1] = 1;
  }
  for (int l = 2; l <= 2 * n; l += 2) {
    for (int i = 1; i + l - 1 <= 2 * n; ++i) {
      int j = i + l - 1;
      if (check(i, j, i + 1, j - 1)) dp[i][j] += dp[i + 1][j - 1];
      if (check(i, i + 1, i + 2, j)) dp[i][j] += dp[i + 2][j];
      if (check(j - 1, j, i, j - 2)) dp[i][j] += dp[i][j - 2];
    }
  }
  printf("%lld\n", dp[1][2 * n]);
}
int main() {
  // freopen("data.in", "r", stdin);
  work();
}
