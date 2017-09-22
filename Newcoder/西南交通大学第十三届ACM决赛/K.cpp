/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 100 + 200;

int cont[maxn];
int a[maxn];
bool vis[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  int n, k, q;
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d%d", &n, &k, &q);
    memset(cont, 0, sizeof(cont));
    for (int x, i = 1; i <= n; ++i) {
      scanf("%d", &x);
      a[i] = x;
      cont[x]++;
    }
    int ans = 0;
    int l = 1, r = l + k - 1;
    while (l <= 100) {
      int ret = 0;
      memset(vis, 0, sizeof(vis));
      // printf("(%d, %d) ", l, r);
      for (int i = l; i <= r; ++i) {
        // printf("%d ", a[i]);
        if (vis[i]) continue;
        ret += cont[i];
        vis[i] = 1;
      }
      // printf("  == %d\n", ret);
      ans += (int)(ret >= q);
      ++l;
      ++r;
    }
    printf("%d\n", ans);
  }
  return 0;
}
