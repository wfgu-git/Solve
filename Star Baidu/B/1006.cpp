#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100000 + 20;
int n, m;
struct Interval {
  int l, r;
  bool operator < (const Interval& rhs) const {
    return l < rhs.l;
  }
} info[maxn];
inline void work() {
  for (int i = 0; i < n; ++i) {
    static int l, r;
    scanf("%d%d", &l, &r);
    info[i] = {l, r};
  }
  sort(info, info + n);
  int ans = 0, Max = 0;
  int l = 0, r = -1, now = info[0].r, need = 0;
  while (r + 1 < n) {
    if (now < info[r + 1].l) {
      int d = info[r + 1].l - now - 1;
      if (need + d <= m) {
        ++r;
        now = max(now, info[r].r);
        need += d;
        if (Max <= now - info[l].l) {
          Max = now - info[l].l;
          ans = max(ans, Max + m - need);
        }
      } else {
        need -= max(0, (info[l + 1].l - info[l].r - 1));
        ++l;
      }
    } else {
      now = max(info[r + 1].r, now);
      ++r;
      if (Max <= now - info[l].l) {
        Max = now - info[l].l;
        ans = max(ans, Max + m - need);
      }
    }
  }
  printf("%d\n", ans + 1);
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    work();
  }
  return 0;
}
