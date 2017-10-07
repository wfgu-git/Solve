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
const int maxn = 2500 + 20;
const ll moder = 998244353;
int n, m, q;
string ans[2] = {"No", "Yes"};
ll a, b, c, d;
ll C[maxn][maxn];
void addy(int x, int y, ll val) {
  while (y <= m) {
    C[x][y] += val;
    y += y & (-y);
  }
}
void addx(int x, int y, ll val) {
  while (x <= n) {
    addy(x, y, val);
    x += x & (-x);
  }
}
ll qryy(int x, int y) {
  ll ret = 0;
  while (y) {
    ret += C[x][y];
    y -= y & (-y);
  }
  return ret;
}
ll qryx(int x, int y) {
  ll ret = 0;
  while (x) {
    ret += qryy(x, y);
    x -= x & (-x);
  }
  return ret;
}
void modify(int x1, int y1, int x2, int y2, ll val) {
  val *= (a * x1 % moder + b * y1 % moder + c * x2 % moder + d * y2 % moder);
  addx(x1, y1, val);
  addx(x1, y2 + 1, -val);
  addx(x2 + 1, y1, -val);
  addx(x2 + 1, y2 + 1, val);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  srand(time(0));
  a = rand() % moder;
  b = rand() % moder;
  c = rand() % moder;
  d = rand() % moder;
  cin >> n >> m >> q;
  int t, r1, c1, r2, c2;
  for (int i = 0; i < q; ++i) {
    cin >> t >> r1 >> c1 >> r2 >> c2;
    if (t != 3) {
      modify(r1, c1, r2, c2, t == 1 ? 1 : -1);
    } else {
      cout << ans[qryx(r1, c1) == qryx(r2, c2)] << "\n";
    }
  }
}
