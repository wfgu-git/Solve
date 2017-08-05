#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
int w[maxn], c[maxn];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int budget, n;
    scanf("%d%d", &budget, &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", w + i, c + i);
    }
  }
  return 0;
}
