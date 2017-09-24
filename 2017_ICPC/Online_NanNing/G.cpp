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
  int T;
  cin >> T;
  ld r;
  cin >> r;
  while (T--) {
    int k;
    cin >> k;
    double r1, r2, r3;
    r1 = r2 = r3 = r;
    for (int i = 0; i < k; ++i) {
      r3 = (r1 * r2 * r3) / ((r1 * r2 + r2 * r3 + r1 * r3) + 2 * sqrt(r1 * r2 * r3 * (r1 + r2 + r3)));
    }
    cout << k << " " << (ll)r3 << endl;
  }
  int x;
  cin >> x;
}
