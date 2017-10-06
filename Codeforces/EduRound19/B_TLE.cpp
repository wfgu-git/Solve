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
const int maxn = 100000 + 20;

int a[maxn];
int dp[maxn][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memset(dp, -0x3f, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    dp[i][a[i] & 1] = a[i];
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < 2; ++k) {
        dp[i][dp[j][k] & 1] = max(dp[i][dp[j][k] & 1], dp[j][k]);
        if (dp[j][k] + a[i] > (dp[i][(dp[j][k] + a[i]) & 1])) {
          dp[i][(dp[j][k] + a[i]) & 1] = dp[j][k] + a[i];
        }
      }
    }
  }
  printf("%d\n", dp[n - 1][1]);
}
