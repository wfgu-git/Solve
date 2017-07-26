#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000 + 20;
const int maxq = 100000 + 20;
using ll = long long;
int n, q;
struct BIT {
  ll a[maxq];
  void init() {
    memset(a, 0, sizeof(a));
  }
  inline int lowbit(int x) {return x & (-x);}
  void update(int x, ll k) {
    while (x <= n) {
      a[x] += k;
      x += lowbit(x);
    }
  }
  ll query(int x) {
    ll res = 0;
    while (x) {
      res += a[x];
      x -= lowbit(x);
    }
    return res;
  }
} bit;
using pii = pair<int, int>;
map<int, vector<pii> > Qs;
map<ll, int> last;
int a[maxn];
ll ans[maxq];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    bit.init();
    Qs.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      static int l, r;
      scanf("%d%d", &l, &r);
      Qs[r].push_back({l, i});
    }
    last.clear();
    map<ll, int> pre, now;
    for (int i = 1; i <= n; i++) {
      now.clear();
      now[a[i]] = i;
      for (pii x : now) {
        if (last[x.first]) bit.update(last[x.first], -a[i]);
        last[x.first] = x.second;
        bit.update(last[x.first], a[i]);
      }
      // pre = now;
      swap(pre, now);
      for (pii x : Qs[i]) {
        ans[x.second] = bit.query(i) - bit.query(x.first - 1);
      }
    }
    for (int i = 0; i < q; i++) {
      printf("%lld\n", ans[i]);
    }
  }
  return 0;
}
