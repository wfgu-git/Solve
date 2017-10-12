/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ll w, r, l;
  while (cin >> l >> r >> w) {
    ll g = __gcd(w, r);
    if ((r / g - 1) * g + w > l) {
      cout << "DEADLOCK";
    } else {
      cout << "OK";
    }
    cout << '\n';
  }
}
