#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2000;
const int maxc = 26;
char s[maxn + 1];
int cost[maxc + 1];
int dp[maxn + 1][maxn + 1];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
      char ch[2];
      int ac, dc;
      scanf("%s%d%d", ch, &ac, &dc);
      cost[ch[0] - 'a'] = min(ac, dc);
    }
    for (int l = 1; l < m; l++) {
      for (int i = 0; i + l < m; i++) {
        int j = i + l;
        dp[i][j] = min(dp[i + 1][j] + cost[s[i] - 'a'], dp[i][j - 1] + cost[s[j] - 'a']);
        if (s[i] == s[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
      }
    }
    printf("%d\n", dp[0][m - 1]);
  }
  return 0;
}
