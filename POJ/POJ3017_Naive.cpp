/*
教练我要打ACM!
*/
/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int mxlg = 20 + 5;

int N;
ll M;
ll a[maxn], cum[maxn];
ll dp[maxn];
ll mx[maxn][mxlg];
multiset<int> tree;
void init() {
  for (int i = 1 ; i <= N; ++i) {
    mx[i][0] = a[i];
  }
  for (int j = 1; (1 << j) <= N; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= N; ++i) {
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int qry(int l, int r) {
  int k = log(r - l + 1) / log(2.0);
  return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
ll sum(int l, int r) {
  return cum[r] - cum[l - 1];
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  // while (~scanf("%d%lld", &N, &M)) {
  scanf("%d%lld", &N, &M);
    cum[0] = 0;
    for (int i = 1; i <= N; ++i) {
      scanf("%lld", a + i);
      cum[i] = cum[i - 1] + a[i];
    }
    init();
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= N; ++i) {
      for (int j = 0; j < i; ++j) {
        if (sum(j + 1, i) <= M) {
          dp[i] = min(dp[i], dp[j] + 1LL * qry(j + 1, i));
          // printf("[%d, %d], %lld,  %lld\n", j + 1, i, sum(j + 1, i), qry(j + 1, i));
        }
      }
    }
    printf("%lld\n", dp[N]);
  // }
  return 0;
}
