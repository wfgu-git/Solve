/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

void work() {
  int n, d;
  cin >> n >> d;

  string str;
  cin >> str;

  int p = 0;
  int ans = 0;
  while (p < n) {
    int r = p + d;
    int i;
    for (i = min(n - 1, r); i >= p + 1; --i) {
      if (str[i] == '1') {
        break;
      }
    }
    if (i == p) {
      break;
    }
    p = i;
    ++ans;
  }
  if (p == n - 1) {
    cout << ans;
  } else {
    cout << -1;
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
