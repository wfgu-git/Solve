#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
int n, q;
struct BIT {
  int a[maxn];
  void init() {
    memset(a, 0, sizeof(a));
  }
  inline int lowbit(int x) {return x & (-x);}
  void update(int x, int k) {
    while (x <= n) {
      a[x] += k;
      x += lowbit(x);
    }
  }
  int query(int x) {
    int res = 0;
    while (x) {
      res += a[x];
      x -= lowbit(x);
    }
    return res;
  }
} bit;
using pii = pair<int, int>;
map<int, vector<pii> > Qs;
map<int, int> last;
int a[maxn], ans[maxn];
int main() {
  while (scanf("%d%d", &n, &q) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    bit.init();
    Qs.clear();
    for (int i = 0; i < q; i++) {
      static int l, r;
      scanf("%d%d", &l, &r);
      Qs[r].push_back({l, i});
    }
    last.clear();
    map<int, int> pre, now;
    for (int i = 1; i <= n; i++) {
      now.clear();
      for (pii x : pre) {
        now[__gcd(x.first, a[i])] = x.second;
      }
      now[a[i]] = i;
      for (pii x : now) {
        if (last[x.first]) bit.update(last[x.first], -1);
        last[x.first] = x.second;
        bit.update(last[x.first], 1);
      }
      pre = now;
      for (pii x : Qs[i]) {
        ans[x.second] = bit.query(i) - bit.query(x.first - 1);
      }
    }
    for (int i = 0; i < q; i++) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
