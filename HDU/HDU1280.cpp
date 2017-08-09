#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 20;
int n, m;
int a[maxn];
int sum[10010];
void work() {
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      ++sum[a[i] + a[j]];
    }
  }
  int k = m;
  vector<int> ans;
  for (int i = 10010 - 1; i >= 0 && k; --i) {
    while (sum[i] && k) {
      --k; --sum[i];
      ans.push_back(i);
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%d%c", ans[i], (i == m - 1 ? '\n' : ' '));
  }
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    work();
  }
  return 0;
}
