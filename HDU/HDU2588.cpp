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

int euler(int n) {
  if (n == 1) {
    return 1;
  }
  int i = 2, m = n, root = (int)sqrt(n);
  while (i <= root) {
    if (m % i == 0) {
      n -= n / i;
      while (m % i == 0) {
        m /= i;
      }
      root = (int)sqrt(m);
    }
    ++i;
  }
  if (m != 1) {
    n -= n / m;
  }
  return n;
}
void work() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        if (i >= m && i * i != n) {
          ans += euler(n / i);
        }
        if (n / i >= m) {
          ans += euler(i);
        }
      }
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
