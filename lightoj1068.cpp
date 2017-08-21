/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 32 + 1;
ll lb, ub, k;
int num[maxn];
ll dp[maxn][90][90];
ll dfs(int pos, ll rems, int sum, int limit) {
  if (pos == -1) return !rems && !sum;
  if (!limit && dp[pos][rems][sum] != -1) return dp[pos][rems][sum];
  int up = (limit ? num[pos] : 9);
  ll tmp = 0;
  for (int i = 0; i <= up; ++i) {
    tmp += dfs(pos - 1, (10LL * rems + i) % k, (sum + i) % k, limit && i == num[pos]);
  }
  if (!limit) dp[pos][rems][sum] = tmp;
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
  return dfs(pos - 1, 0, 0, true);
}
void work(int kase) {
  memset(dp, -1, sizeof(dp));
  cin >> lb >> ub >> k;
  if (k >= 90) {
    cout << "Case " << kase << ": " << 0 << endl;
    return;
  }
  ll ans = solve(ub) - solve(lb - 1);
  cout << "Case " << kase << ": " << ans << endl;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
