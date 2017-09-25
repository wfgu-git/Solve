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
const int maxn = 10000 + 20;

int a, b, f, k;
int d[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> a >> b >> f >> k) {
    if (k == 1 && b < f) {
      cout << -1 << endl;
      continue;
    } else if (k > 1 && (b < 2 * (a - f) || b < 2 * f)) {
      cout << -1 << endl;
      continue;
    }
    d[1] = f;
    d[2] = 2 * (a - f);
    for (int i = 3; i <= k; ++i) {
      if (i & 1) {
        d[i] = 2 * f;
      } else {
        d[i] = 2 * (a - f);
      }
    }
    if (k & 1) {
      d[k + 1] = a - f;
    } else {
      d[k + 1] = f;
    }
    int now = 0, cont = 0;
    for (int i = 1; i <= k + 1; ++i) {
      now += d[i];
      if (now > b) {
        cont++;
        now = d[i];
      }
    }
    cout << cont << endl;
  }
}
