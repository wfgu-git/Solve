#include <bits/stdc++.h>
using namespace std;
long long solve(long long n, long long k) {
  if (k <= n) return k;
  k = k - n;
  int t = k / (n - 1);
  int m = k % (n - 1);
  if (m == 0) {
    if (t % 2 == 1) return n - 1;
    else return n;
  } else {
    return m;
  }
}
int main() {
  int kase = 0;
  long long n, k;
  while (scanf("%lld%lld", &n, &k) == 2) {
    long long ans = solve(n, k);
    printf("Case #%d: %lld\n", ++kase, ans);
  }
  return 0;
}
