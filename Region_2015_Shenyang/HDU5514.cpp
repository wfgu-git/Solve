/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll m;
int n;
ll calc(ll g) {
  return (m / g - 1) * m / 2L;
}
ll ans;
vector<ll> st;
void dfs(int k, ll LCM, int cur) {
  LCM = LCM / __gcd(LCM, st[cur]) * st[cur];
  ll t = calc(LCM);
  if (k & 1) {
    ans += t;
  } else {
    ans -= t;
  }
  for (int i = cur + 1; i < st.size(); ++i) {
    dfs(k + 1, LCM, i);
  }
}
int vis[maxn];
int cnt[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  vector<int> factors;
  for (int cas = 1; cas <= T; ++cas) {
    factors.clear();
    cin >> n >> m;
    for (int i = 1; i * i <= m; ++i) {
      if (m % i == 0) {
        factors.push_back(i);
        if (i * i != m) factors.push_back(m / i);
      }
    }
    sort(factors.begin(), factors.end());
    factors.pop_back();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      int g = __gcd(1LL * x, m);
      for (int j = 0; j < factors.size(); ++j) {
        if (factors[j] % g == 0) {
          vis[j] = 1;
        }
      }
    }
    ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < factors.size(); ++i) {
      if (vis[i] != cnt[i]) {
        int times = vis[i] - cnt[i];
        ans += calc(factors[i]) * times;
        for (int j = i; j < factors.size(); ++j) {
          if (factors[j] % factors[i] == 0) {
            cnt[j] += times;
          }
        }
      }
    }
    cout << "Case #" << cas << ": " << ans << endl;
  }
  return 0;
}
