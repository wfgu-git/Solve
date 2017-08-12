#include <cstdio>
const int maxn = 100000 + 20;
struct UFset {
  int n;
  int fa[maxn], rank[maxn];
  inline void init(int n) {
    this->n = n;
    for (int i = 0; i < maxn; ++i) {
      rank[i] = 0;
      fa[i] = i;
    }
  }
  inline int find(int x) {
    if (x != fa[x]) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }
  inline int unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return 0;

    if (rank[a] < rank[b]) {
      fa[a] = b;
    } else {
      fa[b] = a;
      if (rank[a] == rank[b]) ++rank[a];
    }
    /* 统计某个为祖先有几个元素
    fa[b] = a;
    rank[a] += rank[b];
    */
    return 1;
  }
  inline bool same(int a, int b) {
    return find(a) == find(b);
  }
} ufst;
