/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int moder = 1e9 + 7;

map<ll, ll> dp;
ll mod_pow(ll x, ll b) {
  ll ret = 1, base = x;
  while (b) {
    if (b & 1) {
      ret = ret * base % moder;
    }
    base = base * base % moder;
    b >>= 1;
  }
  return ret;
}
ll dfs(ll t) {
  if (dp.find(t) != dp.end()) {
    return dp[t];
  }
  ll ret = mod_pow(2, t - 1);
  ll tmp = 1;
  int i;
  for (i = 2; i * i < t; ++i) {
    if (t % i == 0) {
      tmp = (tmp + dfs(i)) % moder;
      tmp = (tmp + dfs(t / i)) % moder;
    }
  }
  if (i * i == t) {
    tmp = (tmp + dfs(i)) % moder;
  }
  return dp[t] = (ret - tmp + moder) % moder;
}
void work() {
  dp.insert({1, 1});
  dp.insert({2, 1});
  int x, y;
  cin >> x >> y;
  if (y % x != 0) {
    cout << 0;
    return;
  }
  cout << dfs(y / x) << endl;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
