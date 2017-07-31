#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 20;
struct BIT {
  int n;
  int a[maxn][maxn];
  void init(int _n) {
    n = _n;
    memset(a, 0, sizeof(a));
  }
  inline int lowbit(int x) {return x & (-x);}
  inline void update(int x, int y, int k) {
    while (x <= n) {
      int yy = y;
      while (yy <= n) {
        a[x][yy] += k;
        yy += lowbit(yy);
      }
      x += lowbit(x);
    }
  }
  inline int query(int x, int y) {
    int ret = 0;
    while (x) {
      int yy = y;
      while (yy) {
        ret += a[x][yy];
        yy -= lowbit(yy);
      }
      x -= lowbit(x);
    }
    return ret;
  }
} bit;
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n, q;
    scanf("%d%d", &n, &q);
    bit.init(n);
    for (int i = 0; i < q; ++i) {
      static char op[2];
      char *const cmd = &op[0];
      scanf("%s", op);
      if (*cmd == 'C') {
        static int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        bit.update(x1, y1, 1);
        bit.update(x1, y2 + 1, -1);
        bit.update(x2 + 1, y1, -1);
        bit.update(x2 + 1, y2 + 1, 1);
      } else {
        static int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", bit.query(x, y) % 2);
      }
    }
    if (cas < T) printf("\n");
  }
  return 0;
}
