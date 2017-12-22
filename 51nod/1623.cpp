/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

ll l, r, k;
int a[20];
ll dp[20][20][1 << 10];
int check(int & state, int i) {
  for (int j = i + 1; j <= 9; ++j) {
    if (state & (1 << j)) {
      state ^= (1 << j);
    }
  }
  int flag = state & (1 << i);
  state |= (1 << i);
  return flag;
}
ll dfs(int pos, int nowk, int state, int limit) {
  if (pos < 0) {
    return nowk == k;
  }
  if (!limit && dp[pos][nowk][state] != -1) {
    return dp[pos][nowk][state];
  }
  int up = limit ? a[pos] : 9;
  ll ret = 0;
  for (int i = 0; i <= up; ++i) {
    int ts = state;
    int flag = check(ts, i);
    if (!flag) {
      ret += dfs(pos - 1, nowk + 1, ts, limit && i == a[pos]);
    } else {
      ret += dfs(pos - 1, nowk, ts, limit && i == a[pos]);
    }
  }
  if (!limit) dp[pos][nowk][state] = ret;
  return ret;
}
ll solve(ll x) {
  int pos = 0;
  while (x) {
    a[pos++] = x % 10;
    x /= 10;
  }
  return dfs(pos - 1, 0, (1 << 0), 1);
}
void work() {
  cin >> l >> r >> k;
  memset(dp, -1, sizeof(dp));
  ll ans = solve(r) - solve(l - 1);
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
