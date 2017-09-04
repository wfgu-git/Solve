#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxn = 100000 + 20;
int a[maxn];
int b[maxn];
bool check(int mid, int n, int up) {
  int p = 0;
  int cost = 0;
  int head = 1, tail = 1;
  int x = (n - 1) % (mid - 1) + 1;
  if ((n - 1) % (mid - 1) != 0) {
    for (int i = 0; i < x; ++i) {
      cost += a[i];
    }
    p = x;
    if (cost) b[tail++] = cost;
  }
  while (true) {
    int temp = 0;
    for (int i = 0; i < mid; i++) {
      if (p < n && (head >= tail || a[p] <= b[head])) temp += a[p++];
      else if (head < tail && (p >= n || a[p] >= b[head])) temp += b[head++];
    }
    cost += temp;
    if (p >= n && head >= tail) break;
    b[tail++] = temp;
  }
  return cost <= up;
}
int main() {
  int T;
  scanf("%d", &T);
  int n, up;
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d", &n, &up);
    for_each(a, a + n, [](int &x){scanf("%d", &x);});
    sort(a, a + n);
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
  }
  return 0;
}
