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
int dp[300][maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i  = n; i >= 1; --i) {
    for (int j =  1; j < 300; ++j) {
      dp[j][i] = 1;
      int now = i + a[i] + j;
      if (now <= n) {
        dp[j][i] += dp[j][now];
      }
    }
  }
  int q, p, k;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> p >> k;
    if (k >= 300) {
      int now = p, ans = 0;
      while (now <= n) {
        now = now + a[now] + k;
        ++ans;
      }
      cout << ans << endl;
    } else {
      cout << dp[k][p] << endl;
    }
  }
}
