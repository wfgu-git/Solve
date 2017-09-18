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
  char s[maxn];
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
    for (int k = 1; k <=n; k <<= 1) {
      int p = 0;
      for (i = n - k; i < n; ++i) y[p++] = i;
      for (i = 0; i < n; ++i) if (sa[i] >= k) {
        y[p++] = sa[i] - k;
      }
      for (i = 0; i < m; ++i) c[i] = 0;
      for (i = 0; i < n; ++i) c[x[y[i]]]++;
      for (i = 0; i < m; ++i) c[i] += c[i - 1];
      for (i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
      swap(x, y);
      p = 1;
      x[sa[0]] = 0;
      for (i = 1; i < n; ++i) {
        x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]
        ? p - 1
        : p++;
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
  int cmp_suffix(char* P, int p, int m) {
    return strncmp(P, s+sa[p], m);
  }
  int find(char* P) {
    int m = strlen(P);
    if(cmp_suffix(P, 0, m) < 0) return -1;
    if(cmp_suffix(P, n-1, m) > 0) return -1;
    int L = 0, R = n-1;
    while(R >= L) {
      int M = L + (R-L)/2;
      int res = cmp_suffix(P, M, m);
      if(!res) return M;
      if(res < 0) R = M-1; else L = M+1;
    }
    return -1;
  }
} SA;
char buf[maxn];
int main() {
  int T, Q;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", SA.s);
    SA.n = strlen(SA.s) + 1;
    SA.build_sa('z' + 1);
    scanf("%d", &Q);
    while (Q--) {
      scanf("%s", buf);
      if (SA.find(buf) >= 0) {
        puts("y");
      } else {
        puts("n");
      }
    }
  }
  return 0;
}
