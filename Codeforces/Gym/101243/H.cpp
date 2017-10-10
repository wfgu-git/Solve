/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    ll ans = 8;
    if (n <= 9) {
      for (int i = 1; i < n; ++i) {
        ans *= 9;
      }
      cout << ans << endl;
    } else {
      cout << "344373768";
      for (int i = 0; i < n - 9; ++i) {
        cout << "0";
      }
      cout << endl;
    }
  }
}
