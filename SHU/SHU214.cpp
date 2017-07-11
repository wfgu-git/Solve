#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int a[maxn + 1];
int blksz, blk[maxn];
struct query {
  int l, r, id;
  bool operator < (const query &rhs) const {
    if (blk[l] == blk[rhs.l]) {
      return r < rhs.r;
    }
    return l < rhs.l;
  }
} qry[maxn + 1];
int cnt[maxn + 1];
int ret[maxn + 1];
int ans;
void update(int x, int k) {
  if (k == 1) {
    if (cnt[x] % 2 == 0) ++ans, ++cnt[x];
    else --ans, ++cnt[x];
  } else {
    if (cnt[x] % 2 == 0) ++ans, --cnt[x];
    else --ans, --cnt[x];
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n, q;
    scanf("%d%d", &n, &q);
    blksz = ceil(sqrt(1.0 * n));
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      blk[i] = (i - 1) / blksz;
    }
    for (int i = 0; i < q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      qry[i] = {l, r, i};
    }
    sort(qry, qry + q);

    memset(cnt, 0, sizeof(cnt));
    ans = 0;
    int l = 1, r = 0;
    for (int i = 0; i < q; i++) {
      int now = qry[i].id;
      int ql = qry[i].l;
      int qr = qry[i].r;

      while (ql < l) update(a[--l], 1);
      while (ql > l) update(a[l++], -1);
      while (qr < r) update(a[r--], -1);
      while (qr > r) update(a[++r], 1);

      ret[now] = (ans <= 1) ? 1 : 0;
    }

    printf("Case %d:\n", cas);
    for (int i = 0; i < q; i++) {
      if (ret[i]) printf("YES\n");
      else printf("NO\n");
    }
  }
  return 0;
}
