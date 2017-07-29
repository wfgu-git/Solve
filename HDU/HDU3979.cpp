#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 20;
struct Monster{
  int hp, atk, tim;
  bool operator < (const Monster &rhs) const {
    // return atk / tim > rhs.atk / rhs.tim;
    return rhs.tim * atk > tim * rhs.atk;
  }
} info[maxn];
int n, atk;
long long sum;
void solve(int kase) {
  sort(info, info + n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += 1LL * sum * info[i].tim;
    sum -= info[i].atk;
  }
  printf("Case #%d: %lld\n", kase, ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    sum = 0;
    scanf("%d%d", &n, &atk);
    for (int i = 0; i < n; ++i) {
      static int hp, g;
      scanf("%d%d", &hp, &g);
      sum += 1LL * g;
      info[i] = {hp, g, (int)ceil((double)hp / (double)atk)};
    }
    solve(cas);
  }
  return 0;
}
