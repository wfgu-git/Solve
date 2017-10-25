/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 20;

int dp[3][maxn];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  string line;
  stringstream ss;

  cin >> line;
  int n = line.size();
  dp[0][0] = 0;
  dp[1][0] = 0;
  dp[2][0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[0][i + 1] = dp[0][i] + (line[i] == 'a');
    dp[1][i + 1] = max(dp[0][i], dp[1][i]) + (line[i] == 'b');
    dp[2][i + 1] = max(dp[0][i], max(dp[1][i], dp[2][i])) + (line[i] == 'a');
  }
  cout << max(dp[0][n], max(dp[1][n], dp[2][n]));
}
