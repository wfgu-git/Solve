#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 32 + 1;
int num[maxn];
ll dp[maxn][maxn];
ll lb, ub;
ll dfs(int pos, ll state, int lead, int limit) {
  if (pos == -1) {
    if (lead) return 1LL;
    else return state;
  }
  if (!limit && !lead && dp[pos][state] != -1) return dp[pos][state];
  int up = (limit ? num[pos] : 9);
  ll tmp = 0;
  for (int i = 0; i <= up; ++i) {
    if (lead) {
      tmp += dfs(pos - 1, i == 0, lead && i == 0, limit && i == num[pos]);
    } else {
      if (i == 0) {
        tmp += dfs(pos - 1, state + 1LL, 0, limit && i == num[pos]);
      } else {
        tmp += dfs(pos - 1, state, 0, limit && i == num[pos]);
      }
    }
  }
  if (!limit && !lead) dp[pos][state] = tmp;
  return tmp;
}
ll solve(ll x) {
  if (x < 0) return 0;
  if (x == 0) return 1;
  int pos = 0;
  while (x) {
    num[pos++] = x % 10;
    x /= 10;
  }
  return dfs(pos - 1, 0, 1, 1);
}
void work(int kase) {
  cin >> lb >> ub;
  ll ans = solve(ub) - solve(lb - 1);
  cout << "Case " << kase << ": " << ans << endl;
  // printf("Case %d: %d\n", kase, ans);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
