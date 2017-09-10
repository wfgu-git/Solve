/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 20;

int a[maxn];
int cum[maxn];
int dp[maxn][200];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    cin >> n;
    memset(cum, 0, sizeof(cum));
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      cum[i] = cum[i - 1] + a[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 1; --i) {
      for (int k = 200; k >= 1; --k) {
        if (n - i + 1 < k) {
          dp[i][k] = 0;
        } else {
          if (n - i != k - 1) {
            dp[i][k] = max(-dp[i + k][k] + cum[i + k - 1]- cum[i - 1],
              -dp[i + k + 1][k + 1] + cum[i + k - 1 + 1] - cum[i - 1]);
          } else {
            dp[i][k] = -dp[i + k][k] + cum[i + k - 1] - cum[i - 1];
          }
        }
      }
    }
    cout << dp[1][1] << endl;
  }
}
