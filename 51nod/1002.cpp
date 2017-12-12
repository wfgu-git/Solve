/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 500 + 20;

int a[maxn][maxn];
int dp[maxn][maxn];
void work() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        cin >> a[i][j];
        dp[i][j] = a[i][j];
      }
    }
    for (int i = n - 1; i >= 1; --i) {
      for (int j = 1; j <= i; ++j) {
        dp[i][j] = max(dp[i + 1][j] + a[i][j], dp[i + 1][j + 1] + a[i][j]);
      }
    }
    cout << dp[1][1] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
