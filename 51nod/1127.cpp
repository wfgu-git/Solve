#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxn = 100000 + 20;
char s[maxn];
int sum[26];
inline int getid(char c) {return c - 'A';}
int main() {
  scanf("%s", s);
  int n = strlen(s);
  int l = 0, r = 0;
  int cnt = 0;
  int ans = inf;
  while (true) {
    while (r < n && cnt < 26) {
      int x = getid(s[r++]);
      ++sum[x];
      if (!(sum[x] - 1)) {
        ++cnt;
      }
    }
    if (r >= n) break;
    ans = min(ans, r - l);
    int x = getid(s[l++]);
    if (!--sum[x]) --cnt;
  }
  if (ans == inf) printf("No Solution\n");
  else printf("%d\n", ans);
  return 0;
}
