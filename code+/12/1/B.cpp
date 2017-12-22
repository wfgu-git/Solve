/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

ll n, S, L;
ll H[maxn];
ll A[maxn];
ll mul(ll x, ll y) {
  ll ans = 0;
  while (y) {
    if (y & 1) {
      ans += x;
      if (ans < 0) {
        return -1;
      }
    }
    x += x;
    if (x < 0) {
      return -1;
    }
    y >>= 1;
  }
  return ans;
}
bool check(ll x) {
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    ll t = mul(x, A[i]);
    if (t < 0) {
      return 1;
    } else {
      t += H[i];
      if (t < 0) {
        return 1;
      }
      if (t >= L) {
        sum += t;
        if (sum < 0) {
          return 1;
        }
      }
    }
  }
  return sum >= S;
}
void work() {
  cin >> n >> S >> L;
  for (int i = 1; i <= n; ++i) {
    cin >> H[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  ll lb = 0, ub = (ll)1e18;
  ll ans = 0;
  while (lb <= ub) {
    ll mid = (lb + ub) / 2LL;
    if (check(mid)) {
      ans = mid;
      ub = mid - 1;
    } else {
      lb = mid + 1;
    }
  }
  cout << ans;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
