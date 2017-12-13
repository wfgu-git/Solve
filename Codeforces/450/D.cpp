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
const int moder = 1e9 + 7;

ll mod_pow(ll b) {
  ll ret = 1, base = 2;
  while (b) {
    if (b & 1) {
      ret = ret * base % moder;
    }
    base = base * base % moder;
    b >>= 1;
  }
  return ret;
}
void work() {
  int n, g;
  cin >> g >> n;
  if (n % g != 0) {
    cout << 0;
    return;
  }
  int k = n / g;
  cout << mod_pow(k - 1) - 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
