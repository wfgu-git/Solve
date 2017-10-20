/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const ll moder = 1e9 + 7;

int N, M;
int a[maxn];
int bit[maxn][33];
void update(int x, int b, int k) {
  while (x <= N) {
    bit[x][b] += k;
    x += (x & -x);
  }
}
int query_help(int x, int b) {
  int ret = 0;
  while (x) {
    ret += bit[x][b];
    x -= (x & -x);
  }
  return ret;
}
int query(int l, int r, int b) {
  return query_help(r, b) - query_help(l - 1, b);
}
ll mod_pow(ll a, ll b) {
  ll ret = 1LL, base = a;
  while (b) {
    if (b & 1) {
      ret = ret * base % moder;
    }
    base = base * base % moder;
    b >>= 1;
  }
  return ret;
}
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif

  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < 31; ++j) {
      if ((a[i] >> j) & 1) {
        update(i, j, 1);
      }
    }
  }

  scanf("%d", &M);
  int opt, x, y;
  for (int i = 0; i < M; ++i) {
    scanf("%d%d%d", &opt, &x, &y);
    if (opt & 1) {
      for (int j = 0; j < 31; ++j) {
        if ((a[x] >> j) & 1) {
          update(x, j, -1);
        }
      }
      a[x] = y;
      for (int j = 0; j < 31; ++j) {
        if ((a[x] >> j) & 1) {
          update(x, j, 1);
        }
      }
    } else {
      ll ret = 0;
      for (int j = 0; j < 31; ++j) {
        ll cont = query(x, y, j);
        ret = (ret + 1LL * (1 << j) * (mod_pow(2, cont) - 1LL)) % moder;
      }
      printf("%lld\n", ret);
    }
  }
}
