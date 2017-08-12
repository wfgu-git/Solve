#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 20;
int M;
int n;
char s[maxn];
int a[maxn], b[maxn];
inline int two_pointer(int d) {
  int ret = 0;
  int sum = 0;
  int pl, pr, ql, qr;
  pl = pr = 0;
  ql = qr = pl + d;
  while (true) {
    while (qr < n / 2 && sum + abs(a[pr] - b[qr]) <= M) {
      sum += abs(a[pr] - b[qr]);
      ++pr; ++qr;
      ret = max(ret, pr - pl);
    }
    if (qr >= n) break;
    sum -= abs(a[pl] - b[ql]);
    ++pl; ++ql;
  }
  return ret;
}
inline void work() {
  scanf("%d", &M);
  scanf("%s", s);
  n = strlen(s);
  int ans = 0;
  for (int rev = 0; rev < 2; ++rev) {
    if (rev) reverse(s, s + n);
    for (int i = 0; i < n; ++i) {
      a[i] = s[i] - 'a';
      b[i] = s[n - i - 1] - 'a';
    }
    for (int d = 0; d <= n; ++d) {
      ans = max(ans, two_pointer(d));
    }
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
