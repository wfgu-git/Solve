/*
教练我想打ACM！
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

struct SuffixArray {
  char s[maxn];     // 原始字符数组（最后一个字符应必须是0，而前面的字符必须非0）
  int sa[maxn];     // 后缀数组
  int rank[maxn];   // 名次数组. rank[0]一定是n-1，即最后一个字符
  int height[maxn]; // height数组
  int t[maxn], t2[maxn], c[maxn]; // 辅助数组
  int n; // 字符个数

  void clear() { n = 0; memset(sa, 0, sizeof(sa)); }

  // m为最大字符值加1。调用之前需设置好s和n
  void build_sa(int m) {
    int i, *x = t, *y = t2;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1) {
      int p = 0;
      for(i = n-k; i < n; i++) y[p++] = i;
      for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i]-k;
      for(i = 0; i < m; i++) c[i] = 0;
      for(i = 0; i < n; i++) c[x[y[i]]]++;
      for(i = 1; i < m; i++) c[i] += c[i-1];
      for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
      swap(x, y);
      p = 1; x[sa[0]] = 0;
      for(i = 1; i < n; i++)
        x[sa[i]] = y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k] ? p-1 : p++;
      if(p >= n) break;
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
} ;

char s1[maxn], s2[maxn], str[maxn];
int main() {
  SuffixArray S;
  scanf("%s%s", s1, s2);
  int n = snprintf(S.s, sizeof(S.s), "%s%s", s1, s2);
  // assert(n >= 0);
  S.n = n + 1;
  S.build_sa(128);
  S.build_height();
  int ans = 0;
  int p = strlen(s1);
  // int q = strlen(s2);
  for (int i = 2; i <= n; ++i) {
    if ((S.sa[i - 1] < p && S.sa[i] >= p) || (S.sa[i - 1] >= p && S.sa[i] < p)) {
      ans = max(ans, S.height[i]);
    }
  }
  printf("%d\n", ans);
}
