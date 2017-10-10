/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int T;
int a, b, N;
int digit[10];
int tmp[10];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/solve/data.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> a >> b >> N;
    int up = 0;
    for (int i = 1; a * i * i + b * i <= N; ++i) {
      up = i;
    }
    if (up == 0) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < 10; ++i) digit[i] = 0;
    for (int i = 1; i <= up; ++i) {
      int Y = a * i * i + b * i;
      for (int i = 0; i < 10; ++i) tmp[i] = 0;
      while (Y > 0) {
        tmp[Y % 10]++;
        Y /= 10;
      }
      int mx = *max_element(tmp, tmp + 10);
      for (int i = 0; i < 10; ++i) {
        if (tmp[i] == mx) {
          digit[i]++;
        }
      }
    }
    int ans = 0;
    for (int i = 1; i < 10; ++i) {
      if (digit[i] > digit[ans]) {
        ans = i;
      }
    }
    cout << ans << endl;
  }
}
