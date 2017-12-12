/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 20;
char s[maxn], t[maxn];
int dp[maxn][maxn];
int mark[maxn][maxn];
void out(int x, int y) {
  if (x == 0 || y == 0) return;
  if (mark[x][y] == 0) {
    out(x - 1, y - 1);
    putchar(s[x]);
  } else if (mark[x][y] == -1) {
    out(x - 1, y);
  } else {
    out(x, y - 1);
  }
}
void work() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  int sn = strlen(s + 1);
  int tn = strlen(t + 1);
  for (int i = 1; i <= sn; ++i) {
    for (int j = 1; j <= tn; ++j) {
      if (s[i] == t[j]) {
        mark[i][j] = 0;
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          mark[i][j] = -1;
          dp[i][j] = dp[i - 1][j];
        } else {
          mark[i][j] = 1;
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
  }
  out(sn, tn);
}
int main() {
  // freopen("data.in", "r", stdin);
  work();
}
