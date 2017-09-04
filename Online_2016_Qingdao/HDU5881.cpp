#include <bits/stdc++.h>
using namespace std;
long long solve(long long l, long long r) {
  if (r <= 1) return 0;
  if (r <= 2) return 1;
  if (l == r || l + 1 == r) return 2;
  if (l <= 1) l = 1;
  return (r - l) / 2 + 1;
}
int main() {
  long long l, r;
  while (scanf("%lld%lld", &l, &r) == 2) {
    long long ans = solve(l, r);
    printf("%lld\n", ans);
  }
  return 0;
}
