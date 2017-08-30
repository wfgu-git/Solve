/*
   教练我要打ACM!
   Life has never been fucking so easy...
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  int l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  for (int i = x; i <= y; ++i) {
    ll d = 1LL * k * i;
    if (d >= l && d <= r) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
