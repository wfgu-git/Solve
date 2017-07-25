#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
int a[maxn];
struct Query {
  int l, r, id;
} qry[maxn];
int ans[maxn];
struct BIT {
  int a[maxn];
  void clear() {
    memset(a, 0, sizeof(a));
  }
  void add(int x, int val) {
    for (int i = x; i < maxn; i += (i & -i)) {
      a[i] += val;
    }
  }
  int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
      res += a[i];
    }
    return res;
  }
  int get_sum(int l, int r) {
    return query(r) - query(l - 1);
  }
} bit;
int main() {
  int n, q;
  while (scanf("%d%d", &n, &q) == 2) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < q; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      qry[i] = {l, r, i};
    }
    for (int i = 0; i < q; i++) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
