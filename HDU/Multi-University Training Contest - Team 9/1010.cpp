/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 2500 + 20;

char s[maxn];
char t[maxn];
int dp[maxn][maxn];
void work() {
  memset(dp, 0, sizeof(dp));
  scanf("%s", s + 1); scanf("%s", t + 1);
  int slen = strlen(s + 1);
  int tlen = strlen(t + 1);
  dp[0][0] = 1;
  for (int i = 1; i <= tlen; ++i) {
    if (i == 2 && t[i] == '*') dp[i][0] = 1;
    for (int j = 1; j <= slen; ++j) {
      if (t[i] == '.' || t[i] == s[j]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else if (t[i] == '*') {
        dp[i][j] = dp[i - 1][j] | dp[i - 2][j];
        if (s[j] == s[j - 1] && (dp[i - 1][j - 1] || dp[i][j - 1])) {
          dp[i][j] = 1;
        }
      }
    }
  }
  puts(dp[tlen][slen] ? "yes" : "no");
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
