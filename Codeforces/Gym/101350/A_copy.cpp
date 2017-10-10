/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

int T, n;
string raw;
int pre[maxn];
int o[2][maxn];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif

  cin >> T;
  while (T--) {
    memset(pre, 0, sizeof(pre));
    memset(o, 0, sizeof(o));
    cin >> n >> raw;
    for (int i = 0; i < n; ++i) {
      pre[i + 1] = pre[i] ^ (raw[i] - '0');
    }
    int l = 0, r = 0;
    for (int i = n; i >= 0; --i) {
      if (pre[i]) {
        o[0][i] = o[0][i + 1];
        o[1][i] = o[1][i + 1] + 1;
      } else {
        o[0][i] = o[0][i + 1] + 1;
        o[1][i] = o[1][i + 1];
      }
    }
    raw = "0" + raw;
    int last = n + 1, flag = 0;
    ll ans = 0;
    for (int i = n; i > 0; --i) {
      if (!flag) {
        if (raw[i] == '1') {
          flag = 1;
          last = i;
        }
      } else {
        if (pre[i - 1]) {
          ans += o[0][last + 1];
        } else {
          ans += o[1][last + 1];
        }
        if (raw[i] - '0') last = i;
      }
    }
    cout << ans << '\n';
  }
}
