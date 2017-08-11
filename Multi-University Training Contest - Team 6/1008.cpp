#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 20;
int n, m;
char s[maxn];
inline void work() {
  scanf("%d", &m);
  scanf("%s", s);
  n = strlen(s);
  int mx;
  for (int o = 1; o <= (n - 1) * 2 - 1; ++o) {
    int l = 0, r = n - 1;
    if (o & 1) {
      if (o < n) r = o;
      else l = o - n + 1;
    } else {
      int mid = o / 2;
      if (mid <= (n - 1) / 2) r = mid * 2;
      else l = mid * 2 - r;
    }
    mx = -1;
    int len = 1;
    int sum = abs(s[r] - s[l]);
    int nowl = l, nowr = r;
    while (true) {
      if (len > m) {
        sum -= abs(s[r] - s[l]);
        --r; ++l;
        --nowr; ++nowl;
        sum += abs(s[nowr] - s[nowl]);
      } else {
        mx = max(mx, len);
        --nowr; ++nowl;
        if (nowr <= nowl) break;
        sum += abs(s[nowr] - s[nowl]);
        ++len;
      }
    }
  }
  printf("%d\n", mx);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
