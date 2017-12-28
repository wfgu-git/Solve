#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 20;

int n;
int p[maxn];
int dp[maxn][maxn];
int s[maxn][maxn];
string ans;
void dfs(int l, int r) {
  if (l == r) {
    ans.push_back('A');
    ans.push_back(char('0' + l));
  } else {
    ans.push_back('(');
    dfs(l, s[l][r]);
    dfs(s[l][r] + 1, r);
    ans.push_back(')');
  }
}
int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int kase = 0;
  while (cin >> n) {
    for (int i = 0; i <= n; ++i) {
      cin >> p[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(s, 0, sizeof(s));
    for (int r = 2; r <= n; ++r) {
      for (int i = 1; i + r - 1 <= n; ++i) {
        int j = i + r - 1;
        dp[i][j] = dp[i + 1][j] + p[i - 1] * p[i] * p[j];
        s[i][j] = i;
        for (int k = i + 1; k < j; ++k) {
          int t = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
          if (t < dp[i][j]) {
            dp[i][j] = t;
            s[i][j] = k;
          }
        }
      }
    }
    cout << "Case " << ++kase << '\n' << dp[1][n] << " ";
    ans.clear();
    dfs(1, n);
    if (ans[0] == '(') {
      ans = ans.substr(1, ans.size() - 2);
    }
    cout << ans << endl;
  }
}
