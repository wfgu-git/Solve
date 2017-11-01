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
  int T;
  cin >> T;
  while (T--) {
    ll L, R;
    cin >> L >> R;
    ll x = L;
    for (int i = 62; ~i; --i) if ((R >> i & 1) == 0) {
      if ((x | (1LL << i)) <= R) {
        x |= (1LL << i);
      }
    }
    cout << (x | R) << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
