/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;
const int maxn = 4000 + 20;

int n;
int a[maxn], b[maxn];
int dp[maxn][maxn];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    b[i - 1] = a[i];
  }
  sort(b, b + n);
  int tot = unique(b, b + n) - b;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b, b + tot, a[i]) - b;
  }
  int ans = 1;
  if (n >= 2) ans = 2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < tot; ++j) {
      dp[a[i]][j] = max(dp[a[i]][j], dp[j][a[i]] + 1);
    }
  }
  for (int i = 0; i < tot; ++i) {
    for (int j = 0; j < tot; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
}
