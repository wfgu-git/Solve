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
int dp[maxn][2];
void work() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == 's') {
      if (a[i - 1] == 's') {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = 0;
      } else {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
      }
    } else { // f
      if (a[i - 1] == 's') {
        dp[i][0] = 0;
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
      } else {
        dp[i][0] = 0;
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
      }
    }
  }
  cout << dp[n - 1][0] + dp[n - 1][1] << endl;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
