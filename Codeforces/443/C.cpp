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
  int x = 0, y = 1023;
  for (int i = 0; i < n; ++i) {
    char opt;
    int val;
    cin >> opt >> val;
    if (opt == '&') {
      x &= val;
      y &= val;
    } else if (opt == '|') {
      x |= val;
      y |= val;
    } else {
      x ^= val;
      y ^= val;
    }
  }

  int a = 0, b = 0, c = 0;
  /*
  a &
  b |
  c ^
  */
  for (int i = 0; i < 10; ++i) {
    int nowx = x & (1 << i);
    int nowy = y & (1 << i);
    if (nowx && nowy) {
      b |= (1 << i);
    } else if (!nowx && !nowy) {
      b |= (1 << i);
      c |= (1 << i);
    } else if (!nowx && nowy) {
      ;
    } else if (nowx&& !nowy) {
      c |= (1 << i);
    }
  }
  int ans = (b != 0) + (c != 0);
  cout << ans << endl;
  if (b) {
    cout << "| " << b << endl;
  }
  if (c) {
    cout << "^ " << c << endl;
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
