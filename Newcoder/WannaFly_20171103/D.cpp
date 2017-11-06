/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, a[6];
ll ans = 0;
ll to_integer(const string & str) {
  ll ret = 0;
  for (const char & ch : str) {
    ret *= 10;
    ret += ch - '0';
  }
  return ret;
}
void dfs(ll x, ll depth) {
  if (depth > n) {
    ans = max(ans, x);
    string temp(to_string(x));
    sort(temp.begin(), temp.end());
    do {
      ll tx = to_integer(temp);
      ans = max(ans, tx);
    } while (next_permutation(temp.begin(), temp.end()));
    return;
  }

  ll val = a[depth];
  dfs(val + x, depth + 1);
  string temp(to_string(x));
  sort(temp.begin(), temp.end());
  ll now_sum;
  do {
    now_sum = to_integer(temp);
    now_sum += val;
    dfs(now_sum, depth + 1);
  } while (next_permutation(temp.begin(), temp.end()));
}
void work() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  ll sum = 0;
  dfs(sum, 1);
  cout << ans << endl;
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
