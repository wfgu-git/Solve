#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
int k;
char s[maxn];
int main() {
  scanf("%d", &k);
  scanf("%s", s);
  int n = strlen(s);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += s[i] - '0';
  }
  sort(s, s + n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (sum >= k) break;
    else {
      sum += (9 - (s[i] - '0'));
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
