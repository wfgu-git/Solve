#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int maxn = 5 * 100000 + 20;
pii a[maxn];
int n, k;
list<pii> l;
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      a[i] = {x, i};
      l.push_back(a[i]);
    }
    sort(a, a + n);

  }
  return 0;
}
