#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lb, ub;
const int maxn = 64 + 1;
int num[maxn], dig[maxn];
ll dp[maxn][maxn][2];
/*
dp[i][j][k] :
i : start
j : pos position
k : state = {0, 1};
*/
ll dfs(int st, int pos, int state, int limit) {
  if (pos == -1) return state;
  if (!limit && dp[st][pos][state] != -1) return dp[st][pos][state];
  int up = (limit ? num[pos] : 9);
  ll tmp = 0;
  for (int i = 0; i <= up; ++i) {
    dig[pos] = i;
    if (st == pos && !i) {
      tmp += dfs(st - 1, pos - 1, state, limit && i == num[pos]);
    } else if (state && pos < (st + 1) / 2) {
      tmp += dfs(st, pos - 1, dig[st - pos] == i, limit && i == num[pos]);
    } else {
      tmp += dfs(st, pos - 1, state, limit && i == num[pos]);
    }
  }
  if (!limit) dp[st][pos][state] = tmp;
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
  return dfs(pos - 1, pos - 1, 1, 1);
}
void work(int kase) {
  scanf("%lld%lld", &lb, &ub);
  if (lb > ub) swap(lb, ub);
  ll ans = solve(ub) - solve(lb -1);
  printf("Case %d: %lld\n", kase, ans);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  memset(dp, -1, sizeof(dp));
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
