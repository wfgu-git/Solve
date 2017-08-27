/*
   教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

int d, n;
struct Island {
  double l, r;

  bool operator < (const Island& rhs) const {
    return l < rhs.l;
  }
} ;
void work(int cas) {
  vector<Island> st;
  double x, y;
  int ret = 0;
  int tx, ty;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &tx, &ty);
    if (ret == -1) continue;
    if (ty > d) {
      ret = -1;
      continue;
    }
    x = 1L * tx;
    y = 1L * ty;
    double tr = sqrt(d * d - y * y);
    st.push_back({x - tr, x + tr});
  }

  if (ret == -1) {
    printf("Case %d: %d\n", cas, ret);
    return;
  }
  sort(st.begin(), st.end());
  double now = -1L * numeric_limits<double>::max();
  vector<Island>::iterator it;
  for (it = st.begin(); it != st.end(); ++it) {
    if (now < it->l) {
      ++ret;
      now = it->r;
    } else if (now > it->r) {
      now = it->r;
    }
  }
  printf("Case %d: %d\n", cas, ret);
}
int kase = 0;
int main() {
  //freopen("/home/wfgu/myset/solve/data.in", "r", stdin);
  while (scanf("%d%d", &n, &d) != EOF && n) {
    work(++kase);
  }
  return 0;
}
