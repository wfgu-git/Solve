#include <bits/stdc++.h>
using namespace std;
#define lson o << 1
#define rson o << 1 | 1
const int maxn = 60000 + 20;
// const int inf = 100000;
int val[maxn];
int nn;
struct Segtree {
  struct node {
    int l, r, cnt;
    int lv, rv;
    double ret;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].lv = a[lson].lv;
    a[o].rv = a[rson].rv;
    a[o].cnt = a[lson].cnt + a[rson].cnt - (a[lson].rv == a[rson].lv);
    printf("%d == %d ==> %d\n", a[lson].rv, a[rson].lv, a[lson].rv == a[rson].lv);
    a[o].ret = (double)a[o].cnt / (double)(a[o].r - a[o].l);
    a[o].ret = min(a[o].ret, min(a[lson].ret, a[rson].ret));
    printf("%d, (%d, %d)\n", a[o].cnt, a[o].l, a[o].r);
  }
  void build(int *val, int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r;
    a[o].lv = a[o].rv = -1;
    a[o].cnt = 0;
    a[o].ret = 1;
    if (r - l == 1) {
      a[o].ret = 1;
      a[o].cnt = 1;
      a[o].lv = a[o].rv = val[l];
      return;
    }
    int m = (l + r) / 2;
    build(val, l, m, lson);
    build(val, m, r, rson);
    push_up(o);
  }
  void update(int p, int k, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      a[o].ret = 1;
      a[o].cnt = 1;
      a[o].lv = a[o].rv = k;
      return;
    }
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) update(p, k, lson);
    else update(p, k, rson);
    push_up(o);
  }
  double query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].ret;
    }
    double ret = 1000;
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) ret = min(ret, query(l, m, lson));
    if (r > m) ret = min(ret, query(m, r, rson));
    double temp = (double)(a[lson].cnt + a[rson].cnt - (a[lson].rv == a[rson].lv)) / (double)(a[o].r - a[o].l);
    return min(ret, temp);
  }
} st;
int main() {

/*
沪上有个蔡盛梁,脸长腿长**长
魔表爸爸sub4,空中飞人正面肛
天天指点刘艾文,能把WK虐出翔
十月北京亚锦赛,亚洲冠军不用讲
麻将桥牌15p,多才多艺痴情郎
最爱魔友孙啦啦,撸管射老师脸上
全校第一无卵用,实事求是装逼强
世界魔友齐膜拜,毕竟上海全能王
*/

  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    scanf("%d", &n);
    nn = n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", val + i);
    }
    st.build(val);
    printf("%.10lf\n", st.query(1, n));
  }
  return 0;
}
