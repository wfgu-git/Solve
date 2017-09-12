/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

const int base = 1000009;
unsigned long long hss[maxn];
unsigned long long hst[maxn];
unsigned long long p[maxn];
void init(char s[], int n, unsigned long long hs[]) {
  hs[0] = 0;
  for (int i = 0; i < n; ++i) {
    hs[i + 1] = hs[i] * base + (s[i] - 'a' + 1);
  }
}
unsigned long long get(unsigned long long hs[], int l, int r) {
  return hs[r] - hs[l - 1] * p[r - l + 1];
}
char s[maxn], t[maxn];
int k;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  p[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    p[i] = p[i - 1] * base;
  }

  int n, m;
  while (scanf("%s%s%d", s, t, &k) == 3) {
    n = strlen(s);
    m = strlen(t);
    init(s, n, hss);
    init(t, m, hst);

    int ans = 0;
    for (int i = 0; i <= n - m; ++i) {
      int j = 0, x = 0;
      while (x <= k && j < m) {
        while (j < m && s[i + j] != t[j] && x <= k) {
          ++j;
          ++x;
        }
        if (j >= m || x > k) break;
        int l = j, r = m;
        while (l + 1 < r) {
          int mid = (l + r) / 2;
          unsigned long long h1 = get(hss, i + l + 1, i + mid + 1);
          unsigned long long h2 = get(hst, l + 1, mid + 1);
          if (h1 == h2) {
            l = mid;
          } else {
            r = mid;
          }
        }
        if (l != m - 1) {
          ++x;
        }
        j = l + 2;
      }
      ans += (x <= k);
    }
    printf("%d\n", ans);
  }
}
