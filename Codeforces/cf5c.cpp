#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 20;
int main() {
  static int dp[maxn];
  static char str[maxn];
  scanf("%s", str + 1);
  int slen = strlen(str + 1);
  stack<int> st;
  int cnt, ans;
  ans = cnt = 0;
  for (int i = 1; i <= slen; ++i) {
    if (str[i] == '(') {
      st.push(i);
    } else {
      if (!st.empty()) {
        int l = st.top();
        st.pop();
        dp[i] = dp[l - 1] + (i - l + 1);
        if (ans < dp[i]) {ans = dp[i]; cnt = 1;}
        else if (dp[i] == ans) ++cnt;
      }
    }
  }
  if (ans == 0) cnt = 1;
  printf("%d %d\n", ans, cnt);
  return 0;
}
