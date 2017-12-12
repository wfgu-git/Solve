/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100 + 20;

int a[maxn];
int dp[10000];
void work() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int V = sum / 2;
  for (int i = 0; i < n; ++i) {
    for (int j = V; j >= a[i]; --j) {
      dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
    }
  }
  int ans = abs(dp[V] - (sum - dp[V]));
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
