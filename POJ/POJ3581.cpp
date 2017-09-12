/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

int n, k;
int tmp[maxn];
int rnk[maxn];
bool comp(int i, int j) {
  if (rnk[i] != rnk[j]) {
    return rnk[i] < rnk[j];
  } else {
    int ri = i + k <= n ? rnk[i + k] : -1;
    int rj = j + k <= n ? rnk[j + k] : -1;
    return ri < rj;
  }
}
// void build(const string& S, int *sa) {
void build(int *S, int n, int* sa) {
  for (int i = 0; i <= n; ++i) {
    sa[i] = i;
    rnk[i] = i < n ? S[i] : -1;
  }
  for (k = 1; k <= n; k *= 2) {
    sort(sa, sa + n + 1, comp);
    tmp[sa[0]] = 0;
    for (int i = 1; i <= n; ++i) {
      tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]) ? 1 : 0);
    }
    for (int i = 0; i <= n; ++i) {
      rnk[i] = tmp[i];
    }
  }
}
int str[maxn];
int rev[maxn];
int sa[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", str + i);
  }
  reverse_copy(str, str + n, rev);
  build(rev, n, sa);
  int p1;
  for (int i = 0; i < n; ++i) {
    p1 = n - sa[i];
    if (p1 >= 1 && n - p1 >= 2) {
      break;
    }
  }
  int m = n - p1;
  for (int i = 0, j = m; j < n; ++j, ++i) {
    rev[i] = str[j];
    rev[i + n - m + 1] = str[j];
  }
  reverse_copy(str + p1, str + n, rev);
  reverse_copy(str + p1, str + n, rev + m);
  build(rev, m * 2, sa);
  int p2;
  for (int i = 0; i <= 2 * m; ++i) {
    p2 = p1 + m -sa[i];
    if (p2 - p1 >= 1 && n - p2 >= 1) {
      break;
    }
  }
  reverse(str, str + p1);
  reverse(str + p1, str + p2);
  reverse(str + p2, str + n);
  for (int i = 0; i < n; ++i) {
    printf("%d\n", str[i]);
  }
  return 0;
}
