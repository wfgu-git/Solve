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
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    if (x >= y) {
      cout << "FunkyMonkeys";
    } else {
      cout << "WeWillEatYou";
    }
    cout << '\n';
  }
}
