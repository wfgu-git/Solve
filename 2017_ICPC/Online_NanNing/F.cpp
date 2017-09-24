#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define debug printf("!\n")
#define MAXN (10000 + 20)
#define MAX(a, b) a > b ? a : b
#define blank printf("\n")
#define LL long long
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
#define pqueue priority_queue
#define INF 0x3f3f3f3f

#define ls (rt << 1)
#define rs (rt << 1 | 1)

int n, m;

double hh[MAXN], col[MAXN << 2], len[MAXN << 2];

struct node {
  double l, r, x, c;
  node() {}
  node(double a, double b, double c, double d) : l(a), r(b), x(c), c(d) {}
  bool operator<(const node &b) const { return x < b.x; }
} a[MAXN];

void PushUp(int rt, int l, int r) {
  if (col[rt]) {
    len[rt] = hh[r + 1] - hh[l];
  } else if (l == r)
    len[rt] = 0;
  else {
    len[rt] = len[ls] + len[rs];
  }
}

void update(int val, int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    col[rt] += val;
    PushUp(rt, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) update(val, L, R, l, mid, ls);
  if (R > mid) update(val, L, R, mid + 1, r, rs);
  PushUp(rt, l, r);
}

int main() {
  int i, j, k, t, kase = 1;
  while (~scanf("%d", &n)) {
    if (!n) {
      printf("*\n");
      continue;
    }
    int v = 0;
    double sum = 0;
    for (i = 0; i < n; i++) {
      double x1, y1, x2, y2;
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      hh[v] = y1;
      a[v++] = node(y1, y2, x1, 1);
      hh[v] = y2;
      a[v++] = node(y1, y2, x2, -1);
    }
    sort(hh, hh + v);
    sort(a, a + v);
    int d = 1;
    for (i = 1; i < v; i++) {
      if (hh[i] != hh[i - 1]) hh[d++] = hh[i];
    }
    mem(len, 0);
    mem(col, 0);
    for (i = 0; i < v - 1; i++) {
      int l = lower_bound(hh, hh + d, a[i].l) - hh;
      int r = lower_bound(hh, hh + d, a[i].r) - hh - 1;
      update(a[i].c, l, r, 0, d - 1, 1);
      sum += len[1] * (a[i + 1].x - a[i].x);
      // printf("%lf %lf\n",sum,len[1]);
    }
    // printf("Test case #%d\nTotal explored area: %.2lf\n\n", kase++, sum);
    printf("%.0lf\n", sum);
  }

  return 0;
}
