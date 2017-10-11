/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

int T, n, m;
int a[maxn], b[maxn];
int dp[maxn][maxn];
int main() {
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", b + i);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i] == b[j]) {
          
        }
      }
    }
  }
}
