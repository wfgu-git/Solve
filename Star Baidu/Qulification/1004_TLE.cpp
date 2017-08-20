#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;
int w[maxn], c[maxn];
struct info {
  int score, sum;
  set<int> st;
  bool operator < (const info &rhs) const {
    if (score != rhs.score) return score < rhs.score;
    if (sum != rhs.sum) return sum > rhs.sum;
    set<int>::iterator it = st.begin();
    set<int>::iterator it_rhs = rhs.st.begin();
    while (it != st.end() && it_rhs != st.end()) {
      if (*it != *it_rhs) {
        return *it > *it_rhs;
      }
    }
  return false;
  }
  info() {}
  info(int _score, int _sum, set<int> _st) : score(_score), sum(_sum) {
    st = _st;
  }
} ;
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int budget, n;
    scanf("%d%d", &budget, &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", w + i, c + i);
    }
    vector<info> dp(budget + 2, {-inf, inf, set<int> ()});
    dp[0] = info(0, 0, set<int> ());
    for (int i = 1; i <= n; ++i) {
      for (int j = budget; j >= 0; --j) if (j >= c[i]) {
        info temp = info(dp[j - c[i]].score, dp[j - c[i]].sum, dp[j - c[i]].st);
        temp.score += w[i]; temp.sum += i; temp.st.insert(i);
        dp[j] = (dp[j] < temp ? temp : dp[j]);
        // printf("budget = %d, score = %d, sum = %d\n", j, dp[j].score, dp[j].sum);
      }
    }
    int cost = 0;
    info ans(-inf, inf, set<int> ());
    for (int i = 0; i <= budget; ++i) {
      if (ans < dp[i]) {
        ans = dp[i];
        cost = i;
      }
    }
    printf("Case #%d:\n%d %d\n", cas, ans.score, cost);
    bool fi = true;
    for (set<int>::iterator it = ans.st.begin(); it != ans.st.end(); ++it) {
      if (fi) {fi = false; printf("%d", *it);}
      else printf(" %d", *it);
    }
    puts("");
  }
  return 0;
}
Close
