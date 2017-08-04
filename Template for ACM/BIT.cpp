struct BIT {
  int n;
  int a[maxn];
  void init(int _n) {
    n = _n;
    memset(a, 0, sizeof(a));
  }
  inline int lowbit(int x) {return x & (-x);}
  inline void update(int x, int k) {
    while (x <= n) {
      a[x] += k;
      x += lowbit(x);
    }
  }
  inline int query(int x, int y) {
    int ret = 0;
    while (x) {
      ret += a[x];
      x -= lowbit(x);
    }
    return ret;
  }
} bit;

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
