/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

void work() {
  int n, a, b;
  cin >> n >> a >> b;

  int ans = -inf;
  for (int i = 1; i <= n - 1; ++i) {
    ans = max(ans, min(a / i, b / (n - i)));
  }

  cout << ans << endl;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
