/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

// a(n+1) = 6*a(n)-a(n-1)+2
ll a[30];
void init() {
  a[0] = 0;
  a[1] = 1;
  for (int i = 1; i <= 25; ++i) {
    a[i + 1] = 6 * a[i] - a[i - 1] + 2;
    // cout << a[i + 1] << endl;
  }
}
int main() {
  init();
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    ll n;
    cin >> n;
    bool flag = 0;
    for (int i = 1; i <= 25; ++i) {
      if (a[i] >= n) {
        cout << "Case #" << cas << ": " << a[i] << endl;
        flag = 1;
        break;
      }
    }
    if (!flag) cout << "-1" << endl;
  }
  return 0;
}
