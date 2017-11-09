/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll po5[26];
ll num[26][2];
void work() {
  po5[0] = 1;
  for (int i = 1; i <= 25; ++i) {
    po5[i] = po5[i - 1] * 5;
  }
  num[0][0] = 1;
  num[0][1] = 0;
  for (int i = 1; i <= 25; ++i) {
    if (i & 1) {
      num[i][0] = num[i - 1][0] * 5;
      num[i][1] = num[i - 1][1] * 5;
    } else {
      num[i][0] = 3 * num[i - 1][0] + 2 * num[i - 1][1];
      num[i][1] = 3 * num[i - 1][1] + 2 * num[i - 1][0];
    }
  }

  while (cin >> n) {
    if (n < 0) return;
    ll ans = 0, tmp = 0;
    for (int i = 25; i >= 0; --i) {
      for (int j = 1; j <= n / po5[i]; ++j) {
        ans += num[i][tmp];
        if (i & 1) tmp ^= 1;
      }
      n %= po5[i];
    }
    cout << ans + num[0][tmp] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
