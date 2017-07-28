#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 10000 + 20;
int n;
int a[maxn];
vector<int> m[maxn];
void solve() {
  for (int i = 0; i < n; i++) m[i].clear();
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = x;
    sum += x;
    m[sum % n].push_back(i);
  }
  if (m[0].size() >= 1) {
    auto it = m[0].begin();
    printf("%d\n", *it);
    for (int i = 1; i <= *it; ++i) {
      printf("%d\n", a[i]);
    }
  } else {
    for (int i = 1; i < n; i++) {
      if (m[i].size() > 1) {
        auto fi = m[i].begin();
        auto se = fi + 1;
        printf("%d\n", *se - *fi);
        for (int i = *fi + 1; i <= *se; i++) {
          printf("%d\n", a[i]);
        }
        break;
      }
    }
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    solve();
  }
  return 0;
}
