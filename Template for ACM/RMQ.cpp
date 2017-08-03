#include <bits/stdc++.h>
using namespace std;
struct RMQ {
  void init(const vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) dp[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 0; i + (1 << j) -1 < n; ++i) {
        dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int query(int l, int r) {
    // int k = log(r - l + 1) / log(2.0);
    int k = 0;
    while ((1 << k + 1) <= r - l + 1) ++k;
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
  }
} rmq;
