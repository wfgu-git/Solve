/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll _pow(ll x, int n) {
  ll base = x, ans = 1;
  while (n) {
    if (n & 1)
      ans = ans * base;
    base = base * base;
    n >>= 1;
  }
  return ans;
}
ll k[16], n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i <= 15; ++i) {
    k[i] = _pow(i, i);
  }
  while (cin >> n) {
    bool flag = false;
    for (int i = 1; i <= 15; ++i) {
      if (k[i] > n) {
        cout << i - 1 << endl;
        flag = true;
        break;
      }
    }
    if (!flag) cout << 15 << endl;
  }
  return 0;
}
