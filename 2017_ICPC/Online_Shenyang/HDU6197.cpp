/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int a[maxn];
int dp[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int cont = 0;
    fill(dp, dp + n, inf);
    for (int i = 0; i < n; ++i) {
      *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    cont = lower_bound(dp, dp + n, inf) - dp;
    reverse(a, a + n);
    fill(dp, dp + n, inf);
    for (int i = 0; i < n; ++i) {
      *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    cont = max(cont, (int)(lower_bound(dp, dp + n, inf) - dp));
    if (cont + k >= n) {
      puts("A is a magic array.");
    } else {
      puts("A is not a magic array.");
    }
  }
  return 0;
}
