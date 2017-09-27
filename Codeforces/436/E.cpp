/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

struct node {
  int t, d, p, id;
} a[100 + 10];
int dp[2000 + 10];
int ans;
int n;
vector<int> ret[2000 + 10], ans1;
bool comp(const node& a, const node& b) {
  return a.d < b.d;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    static int t, d, p;
    scanf("%d%d%d", &t, &d, &p);
    a[i] = {t, d, p, i};
  }
  sort(a + 1, a + 1 + n, comp);
  for (int i = 1; i <= n; ++i) {
    for (int j = a[i].d - 1; j >= a[i].t; --j) {
      if (dp[j - a[i].t] + a[i].p > dp[j]) {
        dp[j] = dp[j - a[i].t] + a[i].p;
        ret[j] = ret[j - a[i].t];
        ret[j].push_back(a[i].id);
      }
    }
  }
  int tmp;
  ans = 0;
  for (int i = 0; i <= 2000; ++i) {
    if (dp[i] > ans) {
      ans = dp[i];
      ans1 = ret[i];
    }
  }
  printf("%d\n%d\n", ans, ans1.size());
  for (int i = 0; i < ans1.size(); ++i) {
    printf("%d ", ans1[i]);
  }
}
