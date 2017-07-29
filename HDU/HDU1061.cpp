#include <bits/stdc++.h>
using namespace std;
long long mod_pow(int x, int n) {
  long long ans = 1, base = x % 10;
  while (n) {
    if (n & 1)
      ans = ans * base % 10;
    base = base * base % 10;
    n >>= 1;
  }
  return ans;
}
int solve(int n) {
  return mod_pow(n, n);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    scanf("%d", &n);
    int ans = solve(n);
    printf("%d\n", ans);
  }
  return 0;
}
