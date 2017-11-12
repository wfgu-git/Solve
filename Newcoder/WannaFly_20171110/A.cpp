/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, m;
double a[maxn];
double cum[maxn];
double E[maxn];
double dp[maxn];
void work() {
  scanf("%d%d", &n, &m);
  cum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &a[i]);
    cum[i] = cum[i - 1] + a[i];
  }
  while (m--) {
    int x;
    scanf("%d", &x);
    int flag = 1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > x) {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      puts("YNOI is good OI!");
      continue;
    }
    memset(E, 0, sizeof(E));
    E[n] = dp[n] = 1;
    int c, last = n;
    for (int i = n - 1; i >= 1; --i) {
      while (cum[last] - cum[i - 1] > x) last--;
      c = last - i + 1;
      E[i] = (1.0 / c) * (dp[i + 1] - dp[last + 2]) + 1;
      dp[i] = dp[i + 1] + E[i];
    }
    printf("%.2lf\n", E[1]);
  }
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  freopen("data.in", "r", stdin);
  work();
}
