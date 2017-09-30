/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, k;
int a[maxn], b[maxn];
vector< pair< int, int > > v;
int main() {
  n = read(); k = read();
  ll ans = 0;
  int x, y;
  for (int i = 0; i < n; ++i) {
    x = read(); y = read();
    v.push_back({x, y});
    if ((x & k) == x) {
      ans += y;
    }
  }
  for (int i = 30; i >= 0; --i) if (1 & (k >> i)) {
    // int t = (k ^ (1 << i)) | ((1 << i) - 1);
    int t = k | ((1 << i) - 1);
    ll tmp = 0;
    for (int i = 0; i < n; ++i) {
      if ((v[i].first & t) == v[i].first) {
        tmp += v[i].second;
      }
    }
    ans = max(ans, tmp);
  }
  printf("%lld\n", ans);
}
