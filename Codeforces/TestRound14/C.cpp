/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int lead[10] = {0};
int has[10] = {0};
ll val[10] = {0};
struct  A {
  int ch;
  ll val;
  bool operator < (const A & rhs) const {
    return val > rhs.val;
  }
} info[10];
void work() {
  int n;
  cin >> n;

  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    ll j = 1;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      has[(*it) - 'a'] = 1;
      val[(*it) - 'a'] += j;
      j *= 10;
    }
    lead[s[0] - 'a'] = 1;
  }

  for (int i = 0; i < 10; ++i) {
    info[i] = {i, val[i]};
  }
  sort(info, info + 10);

  int p = -1;
  for (int i = 0; i < 10; ++i) {
    if (!lead[info[i].ch] && has[info[i].ch]) {
      p = i;
      info[i].val = 0;
      break;
    }
  }

  int j = 0;
  for (int i = 0; j <= 9; ++i) {
    if (i != p) info[i].val *= (++j);
  }
  ll ans = 0;
  for (int i = 0; i < 10; ++i) {
    ans += info[i].val;
  }
  cout << ans;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
