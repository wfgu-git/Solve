/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

struct SuffixArray {
  int s[maxn];
  int sa[maxn];
  int rank[maxn];
  int height[maxn];
  int t[maxn], t2[maxn], c[maxn];
  int n;
  void clear() {
    n = 0;
    memset(sa, 0, sizeof(sa));
  }
  void build_sa(int m) {
    int i, *x = t, *y = t2;
    for (i = 0; i < m; ++i) c[i] = 0;
    for (i = 0; i < n; ++i) c[x[i] = s[i]]++;
    for (i = 1; i < m; ++i) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
      int p = 0;
      for (i = n - k; i < n; ++i) y[p++] = i;
      for (i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] -k;
      for (i = 0; i < m; ++i) c[i] = 0;
      for (i = 0; i < n; ++i) c[x[y[i]]]++;
      for (i = 0; i < m; ++i) c[i] += c[i - 1];
      for (i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
      swap(x, y);
      p = 1; x[sa[0]] = 0;
      for (i = 1; i < n; ++i) {
        x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
      }
      if (p >= n) break;
      m = p;
    }
  }
  void build_height() {
    int i, j, k = 0;
    for (i = 0; i < n; ++i) rank[sa[i]] = i;
    for (i = 0; i < n; ++i) {
      if (k) k--;
      int j = sa[rank[i] - 1];
      while (s[i + k] == s[j + k]) k++;
      height[rank[i]] = k;
    }
  }
} ;
SuffixArray sa;
int n;
int a[maxn];
bool check(int x) {
  int min_sa = inf;
  int max_sa = -inf;
  for (int i = 1; i <= n; ++i) {
    if (sa.height[i] < x) {
      min_sa = sa.sa[i];
      max_sa = sa.sa[i];
    } else {
      min_sa = min(min_sa, sa.sa[i]);
      max_sa = max(max_sa, sa.sa[i]);
      if (max_sa - min_sa >= x) {
        // for (int i = min_sa; i < n; ++i) {
        //   cout << sa.s[i];
        // }
        // cout << '\n';
        // for (int i = max_sa; i < n; ++i) {
        //   cout << sa.s[i];
        // }
        // cout << '\n';
        // cout << endl;
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &sa.s[i]);
  }
  sa.n = n + 1;
  sa.build_sa(1024);
  sa.build_height();
  int lb = 0, ub = n;
  int ans = 0;
  while (lb <= ub) {
    int mid = (lb + ub) / 2;
    if (check(mid)) {
      ans = mid;
      lb = mid + 1;
    } else {
      ub = mid - 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
