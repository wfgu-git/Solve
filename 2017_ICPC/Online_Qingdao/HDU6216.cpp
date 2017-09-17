/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll sub[1000000 + 20];
void init() {
  for (ll i = 1; i < 1000000 + 20; ++i) {
    sub[i] = (i * i * i) - ((i - 1) * (i - 1) * (i - 1));
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  init();
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    ll p;
    cin >> p;
    bool flag = 0;
    for (int i = 1; i < 1000000 + 20; ++i) {
      if (p == sub[i]) {
        cout << "YES" << endl;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
