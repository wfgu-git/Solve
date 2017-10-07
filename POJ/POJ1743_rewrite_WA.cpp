/*
教练我想打ACM！
*/
/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 20;

inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

struct SuffixArray {
  int s[maxn];
  int sa[maxn];
  int rank[maxn];
  int height[maxn];
  int t[maxn], t2[maxn], c[500];

  void clear() {
    memset(sa, 0, sizeof(sa));
    memset(height, 0, sizeof(sa));
    memset(rank, 0, sizeof(sa));
  }

  void build_sa(int n, int m) {
    int i;
    int* x = t;
    int* y = t2;
    for (i = 0; i < m; ++i) c[i] = 0; // 清空桶
    for (i = 0; i < n; ++i) c[x[i] = s[i]]++; // 扔进桶
    for (i = 1; i < m; ++i) c[i] += c[i - 1]; // 统计桶信息
    for (i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i; //  第一次CountingSort


    for (int k = 1; k <= n; k <<= 1) {
      int p = 0;
      for (i = n - k; i < n; ++i) y[p++] = i;
      for (i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] - k;
      for (i = 0; i < m; ++i) c[i] = 0;
      for (i = 0; i < n; ++i) c[x[y[i]]]++;
      for (i = 1; i < m; ++i) c[i] += c[i - 1];
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

  void build_height(int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; ++i) rank[sa[i]] = i;
    for (i = 0; i < n; ++i) {
      if (k) --k;
      j = sa[rank[i] - 1];
      while (s[i + k] == s[j + k]) ++k;
      height[rank[i]] = k;
    }
   }

} SA;
int raw[maxn], s[maxn];
bool check(int x, int n) {
  int l = inf, r = -inf;
  for (int i = 2; i <= n; ++i) {
    if (SA.height[i] >= x) {
      l = min(l, min(SA.sa[i - 1], SA.sa[i]));
      r = max(r, max(SA.sa[i - 1], SA.sa[i]));
      if (r - l > x) {
        return 1;
      }
    } else {
      l = inf, r = -inf;
    }
  }
  return 0;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int n;
  while (~scanf("%d", &n) && n) {
    if (n < 10) {
      printf("%d\n", 0);
      continue;
    }
    SA.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", raw + i);
    }
    for (int i = 1; i < n; ++i) {
      SA.s[i - 1] = raw[i] - raw[i - 1] + 100;
    }
    SA.s[--n] = 0;
    SA.build_sa(n + 1, 233);
    SA.build_height(n);
    int ans = 0, lb = 0, ub = n;
    while (lb <= ub) {
      int mid = (lb + ub) / 2;
      if (check(mid, n)) {
        ans = mid;
        lb = mid + 1;
      } else {
        ub = mid - 1;
      }
    }
    // printf("ans = %d\n", ans);
    printf("%d\n", ans < 4 ? 0 : ans + 1);
  }
}
