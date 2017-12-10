/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

vector<ll> factor;
ll Q[maxn];
int top;
void work() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    ll l, r, n;
    cin >> l >> r >> n;
    factor.clear();
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        factor.push_back(i);
        do {
          n /= i;
        } while (n % i == 0);
      }
    }
    if (n > 1) factor.push_back(n);
    int tot = factor.size();

    top = 0;
    Q[top++] = -1;
    for (int i = 0; i < tot; ++i) {
      int k = top;
      for (int j = 0; j < k; ++j) {
        Q[top++] = Q[j] * factor[i] * (-1);
      }
    }
    ll ans, ans1 = 0, ans2 = 0;
    for (int i = 1; i < top; ++i) {
      ans1 += r / Q[i];
    }
    ans1 = r - ans1;
    for (int i = 1; i < top; ++i) {
      ans2 += (l - 1) / Q[i];
    }
    ans2 = l - 1 - ans2;
    ans = ans1 - ans2;
    cout << "Case #" << cas << ": " << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
