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
const int maxn = 4000 + 20;

int n;
int a[maxn], b[maxn];
int dp[maxn][maxn];
int main() {
  n = read();
  for (int i = 0; i < n; ++i) {
    a[i] = read();
    b[i] = a[i];
  }
  sort(b, b + n);
  int tot = unique(b, b + n) - b;
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(b, b + tot, a[i]) - b;
  }
  for (int i = 0; i < n; ++i) {
  }
}
