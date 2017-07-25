#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxn = 100000 + 20;
int a[maxn];
int b[maxn];
bool check(int k, int n, int limit) {
  int nowp, allq, nowq;
  nowp = allq = nowq = 0;
  int cntk = 0;
  int tot = 0, now = 0;
  while (true) {
    if (nowp == n && nowq + 1 == allq) break;
    while (cntk < k) {
      if ((allq == nowq || (allq - nowp >= 1 && a[nowp] < b[nowq])) && nowp < n) {
        now += a[nowp++];
        cntk++;
      } else {
        now += b[nowq++];
        cntk++;
      }
    }
    b[allq++] = now;
    tot += now;
    cntk = now = 0;
  }
  return (tot <= limit) ? true : false;
}
int main() {
  int T;
  scanf("%d", &T);
  int n, up;
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d", &n, &up);
  }
  for_each(a, a + n, [](int &x){scanf("%d", &x);});
  int ans;
  int lb = 2, ub = n;
  while (lb <= ub) {
    int mid = (lb + ub) >> 1;
    if (check(mid, n, up)) {
      ans = mid;
      ub = mid - 1;
    } else {
      lb = mid + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
