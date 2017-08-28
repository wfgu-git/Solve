/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 2100 + 20;

char s[maxn], t[maxn];
int f[maxn][maxn];
int dp[maxn][maxn];
int main() {
  scanf("%s", s + 1); scanf("%s", t + 1);
  int slen = strlen(s + 1);
  int tlen = strlen(t + 1);
  for (int i = 1; i <= slen; ++i) {
    for (int j = 1; j <= tlen; ++j) {
      if (s[i] == t[j]) {
        f[i][j] = f[i - 1][j - 1] + 1;
      } else {
        f[i][j] = 0;
      }
    }
  }
  for (int i = 0; i <= tlen; ++i) dp[0][i] = 0;
  for (int i = 0; i <= slen; ++i) dp[i][0] = 0;
  for (int i = 1; i <= slen; ++i) {
    for (int j = 1; j <= tlen; ++j) {
      dp[i][j] = 0;
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (f[i][j] >= 3) {
        for (int k = 3; k <= f[i][j]; ++k) {
          dp[i][j] = max(dp[i][j], dp[i - k][j - k] + k);
        }
      }
    }
  }
  printf("%d\n", dp[slen][tlen]);
  return 0;
}
