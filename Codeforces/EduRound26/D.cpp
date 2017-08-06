#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
int dp[205][8080];
int two[205], five[205];
int main() {
  int N, K;
  while (scanf("%d%d", &N, &K) != EOF) {
    for (int i = 0; i < N; ++i) {
      ll x;
      scanf("%lld", &x);
      int t = 0, f = 0;
      while (x % 2 == 0) {
        ++t; x /= 2;
      }
      while (x % 5 == 0) {
        ++f; x /= 5;
      }
      two[i] = t; five[i] = f;
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= K; ++j) {
        for (int k = 0; k <= 8000; ++k) {
          tdp[j][k] = dp[j][k];
        }
      }
      for (int j = 0; j < K; ++j) {
        for (int k = 0; k <= 8000; ++k) {
          int tmp = k + five[i];
          if (temp <= 8000) {
            tdp[j + 1][tmp] = max(tdp[j + 1][tmp], dp[j][k] + two[i]);
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < )
  }
  return 0;
}
