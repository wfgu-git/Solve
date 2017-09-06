/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n, a, b;
    cin >> n >> a >> b;
    int t = n / __gcd(a, b);
    if (t & 1) cout << "Case #" << cas << ": Yuwgna" << endl;
    else cout << "Case #" << cas << ": Iaka" << endl;
  }
  return 0;
}
