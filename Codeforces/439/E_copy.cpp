#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 2510;
const ll MOD = 998244353;
typedef long long ll;
int n, m, q;
ll C[MAXN][MAXN], a, b, c, d;

template <typename T>
inline T read() {
  T x(0), f(1);
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
  return x * f;
}

inline void Addy(int x, int y, int val) {
  while (y <= m) {
    C[x][y] += val;
    y += y & (-y);
  }
}

inline void Addx(int x, int y, ll val) {
  while (x <= n) {
    Addy(x, y, val);
    x += x & (-x);
  }
}

inline ll Queryy(int x, int y) {
  ll res = 0;
  while (y) {
    res += C[x][y];
    y -= y & (-y);
  }
  return res;
}

inline ll Queryx(int x, int y) {
  ll res = 0;
  while (x) {
    res += Queryy(x, y);
    x -= x & (-x);
  }
  return res;
}

inline void modify(int x1, int y1, int x2, int y2, ll val) {
  val *= (a * x1 % MOD + b * y1 % MOD + c * x2 % MOD + d * y2 % MOD);
  Addx(x1, y1, val), Addx(x2 + 1, y2 + 1, val);
  Addx(x1, y2 + 1, -val), Addx(x2 + 1, y1, -val);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("869E.in", "r", stdin);
  freopen("869E.out", "w", stdout);
#endif
  srand(time(0));
  a = rand() % MOD, b = rand() % MOD, c = rand() % MOD, d = rand() % MOD;
  n = read<int>();
  m = read<int>();
  q = read<int>();
  while (q--) {
    int t = read<int>();
    int r1 = read<int>(), c1 = read<int>();
    int r2 = read<int>(), c2 = read<int>();
    if (t != 3)
      modify(r1, c1, r2, c2, t == 1 ? 1 : -1);
    else
      printf("%s\n", Queryx(r1, c1) == Queryx(r2, c2) ? "Yes" : "No");
  }
  return 0;
}
