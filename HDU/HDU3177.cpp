#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 20;
struct Equip {
  int a, b;

  bool operator < (const Equip &rhs) const {
    // return a - rhs.a < b - rhs.b;
    return b - a > rhs.b - rhs.a;
  }
} info[maxn];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    bool flag = true;
    int tot, n;
    scanf("%d%d", &tot, &n);
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      info[i] = {a, b};
    }
    sort(info, info + n);
    for (int i = 0; i < n; ++i) {
      const int &need = info[i].b;
      const int &cost = info[i].a;
      if (need > tot) {
        flag = false;
        break;
      } else {
        tot -= cost;
      }
    }
    printf("%s\n", flag ? "Yes" : "No");
  }
  return 0;
}
