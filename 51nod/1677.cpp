/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

vector<int> G[maxn];
ll n, k;
ll ans;
ll sz[maxn];
ll vis[maxn];
ll fac[maxn];
ll inv[maxn];
ll mod_pow(ll x, ll b) {
  ll ret = 1LL, base = x;
  while (b) {
    if (b & 1) {
      ret = ret * base % moder;
    }
    base = base * base % moder;
    b >>= 1;
  }
  return ret;
}
ll C(ll a, ll b) {
  if (b > a) return 0;
  if (b == 0 || a == b) return 1;
  ll ret = fac[a] * inv[b] % moder;
  ret *= inv[a - b];
  ret %= moder;
  return ret;
}
void dfs(int u, int p) {
  sz[u] = 1LL;
  for (int v : G[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      ans = (ans + C(n, k)) % moder;
      ans -= C(sz[v], k);
      ans = (ans + moder) % moder;
      ans -= C(n - sz[v], k);
      ans = (ans + moder) % moder;
    }
  }
}
void work() {
  fac[0] = 1LL;
  for (ll i = 1; i < maxn; ++i) {
    fac[i] = fac[i - 1] * i % moder;
    inv[i] = mod_pow(fac[i], moder - 2);
  }
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    static int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  ans = 0;
  dfs(1, -1);
  cout << ans << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  work();
}
