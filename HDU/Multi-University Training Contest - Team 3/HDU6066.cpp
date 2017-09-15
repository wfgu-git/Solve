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

  int t;
  cin >> t;
  int ans = 0;
  for (int i = 0; i < t; ++i) {
    int x;
    cin >> x;
    if (x <= 35) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
