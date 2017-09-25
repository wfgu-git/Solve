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
  int n;
  string raw;
  cin >> n >> raw;
  set<char> cont;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (raw[i] >= 'A' && raw[i] <= 'Z') {
      cont.clear();
    } else {
      cont.insert(raw[i]);
    }
    ans = max(ans, (int)cont.size());
  }
  cout << ans << endl;
}
