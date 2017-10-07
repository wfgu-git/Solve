#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 20;
int n;
int s[maxn];
int a[maxn], b[maxn];
int x[maxn], y[maxn], c[maxn], tmp[maxn];
int rnk[maxn], sa[maxn], height[maxn];
void build() {
  // 离散化
  copy(s, s + n, b);
  sort(b, b + n);
  int end = unique(b, b + n) - b;
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(b, b + end, s[i]) - b;
  }

  // 对每个字符单独排序， 得到其排名
  for (int i = 0; i < n; ++i) c[i] = 0;
  for (int i = 0; i < n; ++i) c[a[i]]++;
  for (int i = 1; i < n; ++i) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; --i) rnk[i] = --c[a[i]] + 1; // 计数排序 CountingSort

  for (int t = 1; t <= n; t *= 2) {
    // 设置第一、第二关键字
    // x[i] : i位置的第一关键字排名
    // y[i] : i位置的第二关键字排名
    for (int i = 0; i < n; ++i) x[i] = rnk[i];
    for (int i = 0; i < n; ++i) y[i] = i + t < n ? rnk[i + t] : 0;

    for (int i = 0; i < n; ++i) c[i] = 0;
    for (int i = 0; i < n; ++i) c[y[i]]++;
    for (int i = 1; i < n; ++i) c[i] += c[i - 1];
    for (int i = 0; i < n; ++i) tmp[n - --c[y[i]]] = i; // tmp[i] 第i大的位置

    for (int i = 0; i < n; ++i) c[i] = 0;
    for (int i = 0; i < n; ++i) c[x[i]]++;
    for (int i = 1; i < n; ++i) c[i] += c[i - 1];
    for (int j = 0, i; j < n; ++j) i = tmp[j], sa[c[x[i]]--] = i;
    // 对第一关键字排序，相同的时候将按第二关键字排序，
    // 按第二关键字去领排名，最大的排名应该靠后，而sa[k]表示第k大的位置，较早领到排名的那些位置排名靠后。

    bool unique = true;
    for (int j = 0, i, last = -1; j < n; ++j) {
      i = sa[j];
      if (last == -1) rnk[i] = 1;
      else if (x[i] == x[last] && y[i] == y[last]) rnk[i] = rnk[last], unique = false;
      else rnk[i] = rnk[last] + 1;
      last = i;
    }
    if (unique) break;
  }
}

int main() {
  n = 6;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  build();
  for (int i = 0; i < n; ++i) {
    cout << sa[i] << "  ";
  }
}
