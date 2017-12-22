int fa[maxn], rnk[maxn];
int n, k;
void init(int n) {
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    rnk[i] = 0;
  }
}
/*
0 同类
1 吃父结点
2 被父结点吃
*/
int find(int x) {
  if (x != fa[x]) {
    int t = fa[x];
    fa[x] = find(fa[x]);
    rnk[x] = (rnk[x] + rnk[t]) % 3;
  }
  return fa[x];
}
void unite(int x, int y, int r) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) return;
  fa[fx] = fy;
  rnk[fx] = (r + rnk[y] - rnk[x] + 3) % 3;
}
int check(int x, int y, int r) {
  if (x > n || y > n) return 0;
  if (r == 1 && x == y) return 0;
  int tx = find(x);
  int ty = find(y);
  if (tx == ty) {
    return r == (((rnk[x] - rnk[y]) % 3 + 3) % 3);
  }
  return 1;
}
void work() {
  scanf("%d%d", &n, &k);
  init(n);
  int ans = 0;
  int r, x, y;
  for (int i = 0; i < k; ++i) {
    scanf("%d%d%d", &r, &x, &y);
    --r;
    if (check(x, y, r)) unite(x, y, r);
    else ans++;
  }
  printf("%d\n", ans);
}
