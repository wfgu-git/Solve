#include <bits/stdc++.h>
using namespace std;
const int inf = 10000;
const int maxn = 100000;
struct Goods {
  int w, c;

  bool operator < (const Goods &rhs) const {
    if (c == rhs.c) {
      return w > rhs.w;
    }
    return c < rhs.c;
  }
} info[maxn + 1];
int n, m, nn, mm;
bool check(int x) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (mm - info[i].c >= 0 && info[i].w >= x) {
      mm -= info[i].c;
      ++cnt;
    }
    if (mm <= 0) break;
  }
  return cnt >= nn;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &info[i].w, &info[i].c);
    }
    sort(info, info + n);
    nn = 0;
    mm = m;
    for (int i = 0; i < n; ++i) {
      if (mm - info[i].c >= 0) {
        ++nn;
        mm -= info[i].c;
      }
    }

    int lb = 0, ub = inf + 2;
    while (ub - lb > 1) {
      mm = m;
      int mid = lb + (ub - lb) / 2;
      if (check(mid)) lb = mid;
      else ub = mid;
    }
    printf("%d %d\n", nn, lb);
  }
  return 0;
}
