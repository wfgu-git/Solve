#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int r, d, n;
  cin >> r >> d >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x, y, ri;
    cin >> x >> y >> ri;
    double td = sqrt(x * x + y * y);
    if (td - ri  >= r - d && td + ri <= r) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
