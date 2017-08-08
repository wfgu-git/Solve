#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
int mat[maxn][maxn];
int last[maxn * maxn][maxn];
int pre[maxn], suff[maxn], upper[maxn], lower[maxn];
long long ans;
int n, m;
double work() {
  ans = 0LL;
  memset(last, 0, sizeof(last));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &mat[i][j]);
    }
  }
  int totp = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int now = mat[i][j];

      // if (!now) continue;
      // printf("the %d point\n", ++totp);

      memset(upper, 0, sizeof(upper));
      memset(lower, 0x3f, sizeof(lower));
      memset(pre, 0, sizeof(pre));
      memset(suff, 0, sizeof(suff));

      pre[j] = last[now][j];
      for (int k = j - 1; k >= 1; --k) {
        pre[k] = max(pre[k + 1], last[now][k]);
      }
      for (int k = 0; k <= j; ++k) {
        upper[pre[k]] = k + 1;
      }
      upper[i] = max(upper[i], 1);
      for (int k = i - 1; k >= 1; --k) {
        upper[k] = max(upper[k], upper[k + 1]);
      }

      suff[j] = last[now][j];
      for (int k = j + 1; k <= m; ++k) {
        suff[k] = max(suff[k - 1], last[now][k]);
      }
      for (int k = m; k >=j; --k) {
        lower[suff[k]] = k - 1;
      }
      lower[i] = min(lower[i], m);
      for (int k = i - 1; k >= 1; --k) {
        lower[k] = min(lower[k], lower[k + 1]);
      }

      last[now][j] = i;

      for (int k = 1; k <= i; ++k) {
        if (upper[k] > j || lower[k] < j) continue;
        int up = j - upper[k] + 1;
        int down = lower[k] - j + 1;
        // printf("line = %d, l = %d, r = %d\n", k, upper[k], lower[k]);
        ans += 1LL * up * down * (n - i + 1);
      }
    }
  }
  long long tot = (n + 1LL) * (m + 1LL) * n * m;
  return 4L * ans / (double)tot;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    printf("%.9f\n", work());
  }
  return 0;
}

/*
100
6 13
0 1 0 0 0 0 0 0 0 1 0 0 0
1 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 2 0 0 0 0 0 0
0 0 0 0 0 2 0 0 0 0 0 0 0
*/
