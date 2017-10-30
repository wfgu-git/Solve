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
  int n;
  cin >> n;
  string str;
  int ans = 0;
  while (n--) {
    cin >> str;
    switch (str[0]) {
      case 'T': ans += 4; break;
      case 'C': ans += 6; break;
      case 'O': ans += 8; break;
      case 'D': ans += 12; break;
      case 'I': ans += 20; break;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
