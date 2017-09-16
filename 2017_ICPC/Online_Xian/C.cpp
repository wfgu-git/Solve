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
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    string raw = to_string(x);
    int n = raw.size() - 1;
    cout << 1;
    for (int i = 0; i < 233 - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << 0;
      }
      cout << 1;
    }
    cout << endl;
  }
  return 0;
}
