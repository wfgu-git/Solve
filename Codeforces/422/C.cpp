#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 20;
const int inf = INT_MAX;
vector < pair < int, int > > a[maxn], b[maxn];
int cost[maxn];
int main() {
  for (int i = 0; i < maxn; i++) cost[i] = inf;
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    a[l].push_back({r - l + 1, c});
    b[r].push_back({r - l + 1, c});
  }
  int ans = inf;
  for (int i = 0; i < maxn; i++) {
    for (auto x : a[i]) {
      int last = x.first;
      if (last >= d) continue;
      int c = x.second;
      if (cost[d - last] < inf) {
        ans = min(ans, cost[d - last] + c);
      }
    }
    for (auto x : b[i]) {
      cost[x.first] = min(cost[x.first], x.second);
    }
  }
  if (ans == inf) printf("-1\n");
  else printf("%d\n", ans);
  return 0;
}
