#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 20;
int n, m;
char s[maxn];
inline void check(int o) {
  int l = 0, r = n - 1;
  if (o & 1) {

  } else {
    int mid = o / 2;
    if (mid <= (n -1) / 2) r = mid * 2;
    else l = mid * 2 - r;
  }
}
inline void work() {
  scanf("%d", &m);
  scanf("%s", s);
  n = strlen(s);
  for (int o = 1; o <= (n - 1) * 2 - 1; ++o) {
    check(o);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
