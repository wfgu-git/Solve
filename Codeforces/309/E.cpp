/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int moder = 1e9 + 7;
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
      int t = find(fa[x]);
      rank[x] ^= rank[fa[x]];
      fa[x] = t;
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

int N, M;
ll mod_pow(ll x, int n) {
  ll ans = 1, base = x % moder;
  while (n) {
    if (n & 1)
      ans = ans * base % moder;
    base = base * base % moder;
    n >>= 1;
  }
  return ans;
}
void work() {
  ufst.init(N);
  bool flag = false;
  for (int i = 0; i < M; ++i) {
    int u, v, tag;
    scanf("%d%d%d", &u, &v, &tag);
    int x = ufst.find(u);
    int y = ufst.find(v);
    if (x != y) {
      ufst.rank[y] = ufst.rank[u] ^ ufst.rank[v] ^ tag ^ 1;
      ufst.fa[y] = x;
    } else {
      if (ufst.rank[u] != ufst.rank[v] && tag) {
        flag = true;
      } else if (ufst.rank[u] == ufst.rank[v] && !tag) {
        flag = true;
      }
    }
  }
  if (flag) {
    puts("0");
    return;
  }
  int k = 0;
  for (int i = 1; i <= N; ++i) {
    if (i == ufst.find(i)) ++k;
  }
  ll ans = mod_pow(2, k - 1);
  printf("%lld\n", ans % moder);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
