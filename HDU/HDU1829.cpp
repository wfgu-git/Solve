/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 20;


char *out[] = {"Suspicious bugs found!\n", "No suspicious bugs found!\n"};
int n, m;
int fa[maxn], rnk[maxn];
void init() {
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    rnk[i] = 0;
  }
}
int find(int x) {
  if (x != fa[x]) {
    int t = fa[x];
    fa[x] = find(fa[x]);
    rnk[x] = (rnk[x] + rnk[t]) % 2;
  }
  return fa[x];
}
void unite(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) return;
  fa[fx] = fy;
  rnk[fx] = (1 + rnk[y] - rnk[x] + 2) % 2;
}
int check(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) {
    return 1 == ((rnk[x] - rnk[y]) % 2 + 2) % 2;
  }
  return 1;
}
void work() {
  int t;
  int kase = 0;
  scanf("%d", &t);
  while (t--) {
    int flag = 1;
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      if (check(u, v)) {
        unite(u, v);
      } else {
        flag = 0;
      }
    }
    printf("Scenario #%d:\n%s\n", ++kase, out[flag]);
  }
}
int main() {
  work();
}
