#include <cstdio>
const int maxn = 100000 + 20;
struct UFset {
  int n;
  int fa[maxn], rank[maxn];
  void init(int n) {
    this->n = n;
    for (int i = 0; i < maxn; ++i) {
      rank[i] = 0;
      fa[i] = i;
    }
  }
  int find(int x) {
    if (x != fa[x]) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return 0;

    if (rank[x] < rank[y]) {
      fa[x] = y;
    } else {
      fa[y] = x;
      if (rank[x] == rank[y]) ++rank[x];
    }
    /* 统计某个为祖先有几个元素
    fa[y] = x;
    rank[x] += rank[y];
    */
    return 1;
  }
} ufst;
