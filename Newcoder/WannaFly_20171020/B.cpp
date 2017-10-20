/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll a[maxn];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }

  ll ans = 0;

  ll min_val, max_val;
  int min_pos, max_pos;
  min_val = LONG_LONG_MAX;
  max_val = LONG_LONG_MIN;
  for (ll i = 1; i <= n; ++i) {
    ll temp = i * i + a[i] * a[i];
    if (min_val > temp) {
      min_val = temp;
      min_pos = i;
    }
    if (max_val < temp) {
      max_val = temp;
      max_pos = i;
    }
  }
  if (min_pos < max_pos && a[min_pos] < a[max_pos]) {
    ans = max(ans, max_val - min_val);
  }
  min_val = LONG_LONG_MAX;
  max_val = LONG_LONG_MIN;
  for (ll i = 1; i <= n; ++i) {
    ll temp = i * i - a[i] * a[i];
    if (min_val > temp) {
      min_val = temp;
      min_pos = i;
    }
    if (max_val < temp) {
      max_val = temp;
      max_pos = i;
    }
  }
  if (min_pos < max_pos && a[min_pos] > a[max_pos]) {
    ans = max(ans, max_val - min_val);
  }

  cout << ans;
}
