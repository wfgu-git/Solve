#include <bits/stdc++.h>
using namespace std;
struct Treap {
  Treap* ch[2];
  long long key;
  int fix, size;

  Treap(long long x) : key(x) {
    size = 1;
    fix = rand();
    ch[0] = ch[1] = NULL;
  }
  int comp(long long x) const {
    if (x == key) return -1;
    return x < key ? 0 : 1;
  }
  void maintain() {
    size = 1;
    if (ch[0] != NULL) size += ch[0]->size;
    if (ch[1] != NULL) size += ch[1]->size;
  }
};
void rotate(Treap* &o, int d) {
  Treap* k = o->ch[d ^ 1];
  o->ch[d ^ 1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}
void insert(Treap* &o, int x) {
  if (o == NULL) {
    o = new Treap(x);
  } else {
    int d = (x < o->key ? 0 : 1);
    insert(o->ch[d], x);
    if (o->ch[d]->fix > o->fix) rotate(o, d ^ 1);
  }
  o->maintain();
}
void remove(Treap* &o, long long x) {
  int d = o->comp(x);
  if (d == -1) {
    Treap* u = o;
    if (o->ch[0] != NULL && o->ch[1] != NULL) {
      int dd = (o->ch[0]->fix > o->ch[1]->fix ? 1 : 0);
      rotate(o, dd);
      remove(o->ch[dd], x);
    } else {
      if (o->ch[0] == NULL) o = o->ch[1];
      else o = o->ch[0];
      delete u;
      u = NULL;
    }
  } else {
    remove(o->ch[d], x);
  }
  if (o != NULL) o->maintain();
}
void clear(Treap* &o) {
  if (o == NULL) return;
  if (o->ch[0] != NULL) clear(o->ch[0]);
  if (o->ch[1] != NULL) clear(o->ch[1]);
  delete o;
  o = NULL;
}
int Kth(Treap* o, int k) {
  if (o == NULL || k <= 0 || k > o->size) return -1;
  int sz = o->ch[0] == NULL ? 0 : o->ch[0]->size;
  if (sz + 1 == k) return o->key;
  else if (sz >= k) return Kth(o->ch[0], k);
  else return Kth(o->ch[1], k - sz - 1);
}
int Rnk(Treap* o, long long x) {
  int r;
  if (o == NULL) return 0;
  if (o->ch[0] == NULL) r = 0;
  else r = o->ch[0]->size;
  if (x == o->key) return r + 1;
  if (x < o->key) return Rnk(o->ch[0], x);
  else return r + 1 + Rnk(o->ch[1], x);
}
const int maxn = 1e5 + 100;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
int n, ans;
long long k;
long long a[maxn + 1];
int in[maxn + 1];
// vector< vector< int > > g;
vector< int > g[maxn + 1];
Treap* tree;
void dfs(int u, int p) {
  if (a[u] == 0) ans += Rnk(tree, inf);
  else ans += Rnk(tree, k / a[u]);
  insert(tree, a[u]);
  for (auto v : g[u]) {
    if (v == p)continue;
    dfs(v, u);
  }
  remove(tree, a[u]);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    tree = NULL;
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) g[i].clear(), in[i] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      in[v]++;
    }
    int st;
    for (int i = 0; i < n; i++) {
      if (!in[i]) {
        st = i; break;
      }
    }
    ans = 0;
    dfs(st, -1);
    printf("%d\n", ans);
    clear(tree);
  }
  return 0;
}
