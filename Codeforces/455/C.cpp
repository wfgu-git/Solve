/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 20;
const int moder = 1e9 + 7;

char a[maxn];
int dp[maxn][maxn];
void work() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] == 'f') {
      dp[i][0] = 0;
      for (int j = 1; j <= i; ++j) {
        dp[i][j] = dp[i - 1][j - 1];
      }
    } else {
      int t = 0;
      for (int j = 0; j < i; ++j) {
        t += dp[i - 1][j];
        t %= moder;
      }
      for (int j = 0; j < i; ++j) {

      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += dp[n - 1][i];
    ans %= moder;
  }
  cout << ans << endl;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
