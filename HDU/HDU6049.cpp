/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 20;

int N;
int a[maxn];
int dp[maxn][maxn];
int Min[maxn][maxn];
int Max[maxn][maxn];
int main() {
  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    memset(dp, 0, sizeof(dp));
    cin >> N;
    for (int i = 1; i <= N; ++i) {
      cin >> a[i];
    }

    for (int i = 1; i <= N; ++i) {
      Min[i][i] = Max[i][i] = a[i];
      for (int j = i + 1; j <= N; ++j) {
        Min[i][j] = min(Min[i][j - 1], a[j]);
        Max[i][j] = max(Max[i][j - 1], a[j]);
      }
    }
    for (int i = 1; i <= N; ++i) {
      int cont = 1;
      dp[i][i] = 1;
      for (int j = i + 1; j <= N; ++j) {
        if (Min[i][j] != Min[i][j - 1]) {
          cont = 0;
        }
        if (j - i == Max[i][j] - Min[i][j]) {
          dp[i][j] = ++cont;
        }
      }
    }

    int ans = dp[1][N];
    for (int i = 1; i <= N; ++i) {
      for (int j = i; j <= N; ++j) {
        if (dp[i][j]) {
          if (i == 1 || (Min[1][i - 1] == 1 && Max[1][i - 1] - Min[1][i - 1] == i - 2)) {
            int t = Max[i][j];
            if (t == N || (Max[t + 1][N] == N && Max[t + 1][N] - Min[t + 1][N] == N - t - 1)) {
              for (int k = t; k > j; --k) {
                if (dp[k][t] && Min[k][t] == i) {
                  ans = max(ans, dp[1][i - 1] + 1 + dp[j + 1][k - 1] + 1 + dp[t + 1][N]);
                }
              }
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
