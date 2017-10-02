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

ll n, k;
ll a[maxn];
ll cum[maxn];
int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cum[i] = cum[i - 1] + a[i];
  }
  int id;
  int ax = -1;
  for (int i = 1; i <= n; ++i) {
    if (ax < a[i]) {
      ax = a[i];
      id = i;
    }
  }
  ll l = n - 1 + ax;
  ll r = cum[n];
  if (k == 0) {
    if (id == 1) cout << "YES" << endl;
    else cout << "KEK" << endl;
  } else {
    bool flag = false;
    ll turn = 0;
    while (true) {
      if (turn * l + id - 1 > k) break;
      if (turn * r + cum[id - 1] >= k) {
        flag = 1;
        break;
      }
      ++turn;
    }
    if (flag) cout << "YES" << endl;
    else cout << "KEK" << endl;
  }
}
