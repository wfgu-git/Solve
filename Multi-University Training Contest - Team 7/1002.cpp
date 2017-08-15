#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K;
int computerXOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
inline void work() {
  scanf("%lld%lld", &N, &K);
  ll all = 0, now = 1;
  while (true) {
    if (all > N - now) break;
    all += now;
    now *= K;
  }
  ll left = N - all;

}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
