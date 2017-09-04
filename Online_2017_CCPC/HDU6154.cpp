#include <bits/stdc++.h>
using namespace std;
long long N;
long long a[4];
void work() {
  scanf("%lld", &N);
  if (N == 1) {
    printf("4\n");
    return;
  }
  // long long ans;
  long long t = 0;
  while (true) {
    if (N >= 2LL * t * t && N < 2LL * (t + 1LL) * (t + 1LL)) {
      if (N == 2LL * t * t) {
        printf("%lld\n", 4LL * t);
        return;
      } else if (N < 2LL * t * t + t) {
        printf("%lld\n", 4LL * t + 1);
        return;
      } else if (N <= 2LL * t * t + 2LL * t) {
        printf("%lld\n", 4LL * t + 2);
        return;
      } else if (N <= 2LL * t * t + 3LL * t) {
        printf("%lld\n", 4LL * t + 3);
        return;
      } else {
        printf("%lld\n", 4LL * t + 4);
        return;
      }
    }
    ++t;
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
