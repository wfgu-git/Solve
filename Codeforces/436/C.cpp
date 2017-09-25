/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  int a, b, f, k;
  cin >> a >> b >> f >> k;
  int ans = 0;
  int c = b, d;
  if (b < f) {
    ans = -1;
  } else {
    c -= f;
  }
  for (int i = 0; i < k; ++i) {
    if (ans == -1) {
      break;
    }
    if (i & 1) {
      d = f;
    } else {
      d = a - f;
    }
    if (i < k - 1) {
      d *= 2;
    }
    if ( b < d ) {
      ans = -1;
    } else if (c < d) {
      ++ans;
      c = b;
    }
    c -= d;
  }
  cout << ans << endl;
}
