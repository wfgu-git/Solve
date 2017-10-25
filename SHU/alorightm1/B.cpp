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
char a[maxn], b[maxn];
int dp[maxn][maxn];
int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i] == b[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
      }
    }
    cout << "Case " << cas << '\n';
    cout << dp[n][m] << endl;
  }
}
