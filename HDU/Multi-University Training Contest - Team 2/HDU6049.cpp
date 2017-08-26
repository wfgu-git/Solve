/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 20;

int n;
int a[maxn];
int last[maxn];
int Min[maxn][maxn];
int Max[maxn][maxn];
int dp[maxn][maxn];
void work() {
  memset(Min, 0x3f, sizeof(Min));
  memset(Max, 0, sizeof(Max));
  memset(dp, 0, sizeof(dp));

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    last[i] = a[i];
    Min[i][i] = a[i];
    Max[i][i] = a[i];
    dp[i][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      Min[i][j] = min(Min[i][j - 1], a[j]);
      Max[i][j] = max(Max[i][j - 1], a[j]);
    }
  }

  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i + len - 1 <= n; ++i) {
      int j = i + len - 1;
      if (Max[i][j] - Min[i][j] + 1 != len) {
        dp[i][j] = 0;
      } else {
        if (Min[i][last[i]] > Min[i][j]) {

        } else {
          Min[i][j] =
        }
      }
    }
  }

}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
