#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int moder = 1e9 + 7;
int n;
int ans;
int a[N], f[N], po[N];
inline void work() {
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }

  po[0] = 1;
  for (int i = 1; i <= n; ++i) po[i] = 2 * po[i - 1] % moder;

  for (int i = N - 1; i > 1; --i) {
    int x = 0;
    for (int j = i; j < N; j += i) {
      x += a[j];
    }
    if (x) {
      f[i] = 1LL * x * po[x - 1] % moder;
      for (int j = i + i; j < N; j += i) {
        f[i] = (f[i] - f[j] + moder) % moder;
      }
      ans = (1LL * f[i] * i + ans) % moder;
    }
  }
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    work();
  }
  return 0;
}
