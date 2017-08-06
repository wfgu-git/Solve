#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;
int w[maxn], c[maxn];
struct info {
  int score, sum;
  vector<int> kind;
  bool operator < (const info &rhs) const {
    if (score != rhs.score) return score < rhs.score;
    if (sum != rhs.sum) return sum > rhs.sum;
    int n = min(kind.size(), rhs.kind.size());
    for (int i = 0; i < n; ++i) {
      if (kind[i] != rhs.kind[i]) {
        return kind[i] > rhs.kind[i];
      }
    }
    return false;
  }
} dp[1010];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int budget, n;
    scanf("%d%d", &budget, &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", w + i, c + i);
    }
    for (int i = 0; i <= budget; i++) {
      if (!i) {
        dp[i] = {0, 0, vector<int> ()};
        continue;
      }
      dp[i] = {-inf, inf, vector<int> ()};
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = budget; j >= 0; --j) if (j >= c[i]) {
        info temp = {dp[j - c[i]].score, dp[j - c[i]].sum, dp[j - c[i]].kind};
        temp.score += w[i]; temp.sum += i; temp.kind.push_back(i);
        dp[j] = (dp[j] < temp ? temp : dp[j]);
        // printf("budget = %d, score = %d, sum = %d\n", j, dp[j].score, dp[j].sum);
      }
    }
    int cost = 0;
    info ans = {0, 0, vector<int> ()};
    for (int i = 0;  i <= budget; ++i) {
      if (ans < dp[i]) {
        ans = dp[i];
        cost = i;
      }
    }
    printf("Case #%d:\n%d %d\n", cas, ans.score, cost);
    if (ans.kind.size()) {
      bool fi = true;
      for (int &x : ans.kind) {
        if (fi) {
          fi = false;
          printf("%d", x);
          continue;
        }
        printf(" %d", x);
      }
      printf("\n");
    }
  }
  return 0;
}
