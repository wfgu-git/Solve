/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n;
char ch[maxn];
int s[maxn];
int a[maxn], b[maxn];
int x[maxn], y[maxn], c[maxn], tmp[maxn];
int rnk[maxn], sa[maxn], height[maxn];
void build() {
  // 离散化
  copy(s + 1, s + n + 1, b + 1);
  sort(b + 1, b + n + 1);
  int *end = unique(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b + 1, end, s[i]) - b;
  }

  // 对每个字符单独排序， 得到其排名
  for (int i = 1; i <= n; ++i) c[i] = 0;
  for (int i = 1; i <= n; ++i) c[a[i]]++;
  for (int i = 1; i <= n; ++i) c[i] += c[i - 1];
  for (int i = n; i >= 1; --i) rnk[i] = c[a[i] - 1] + 1; // 计数排序 CountingSort

  for (int t = 1; t <= n; t *= 2) {
    // 设置第一、第二关键字
    // x[i] : i位置的第一关键字排名
    // y[i] : i位置的第二关键字排名
    for (int i = 1; i <= n; ++i) x[i] = rnk[i];
    for (int i = 1; i <= n; ++i) y[i] = i + t > n ? 0 : rnk[i + t];

    for (int i = 1; i <= n; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) c[y[i]]++;
    for (int i = 1; i <= n; ++i) c[i] += c[i - 1];
    for (int i = 1; i <= n; ++i) tmp[n - --c[y[i]]] = i; // tmp[i] 第i大的位置

    for (int i = 1; i <= n; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) c[x[i]]++;
    for (int i = 1; i <= n; ++i) c[i] += c[i - 1];
    for (int j = 1, i; j <= n; ++j) i = tmp[j], sa[c[x[i]]--] = i;
    // 对第一关键字排序，相同的时候将按第二关键字排序，
    // 按第二关键字去领排名，最大的排名应该靠后，而sa[k]表示第k大的位置，较早领到排名的那些位置排名靠后。

    bool unique = true;
    for (int j = 1, i, last = 0; j <= n; ++j) {
      i = sa[j];
      if (!last) rnk[i] = 1;
      else if (x[i] == x[last] && y[i] == y[last]) rnk[i] = rnk[last], unique = false;
      else rnk[i] = rnk[last] + 1;
      last = i;
    }
    if (unique) break;
  }

  for (int i = 1, k = 0; i <= n; ++i) {
    if (rnk[i] == 1) {
      k = 0;
    } else {
      if (k > 0) --k;
      int j = sa[rnk[i] - 1];
      while (i + k <= n && j + k <= n && a[i + k] == a[j + k]) ++k;
    }
    height[rnk[i]] = k;
  }
}

int main() {
  n = 6;
  for (int i = 1; i <= n; ++i) {
    cin >> ch[i];
  }
  for (int i = 1; i <= n; ++i) s[i] = ch[i];
  build();
  for (int i = 1; i <= n; ++i) {
    cout << height[i] << " ";
  }
}
