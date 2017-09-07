/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    ld R;
    int n;
    cin >> R >> n;
    ld r = sin(acos(-1.0) / (ld)n) * R / (1L + sin(acos(-1.0) / (ld)n));
    cout << setiosflags(ios::fixed);
    cout << "Scenario #" << setprecision(3) << cas << ":\n" << r << "\n\n";
  }
  return 0;
}
