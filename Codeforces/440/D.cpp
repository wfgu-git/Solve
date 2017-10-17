/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 20;

int num[maxn][maxn];
int p[maxn];
int b[maxn];
int ans[maxn];
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("? %d %d\n", 0, i);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    num[0][i] = x;
  }
  for (int i = 1; i < n; ++i) {
    printf("? %d %d\n", i, 0);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    num[i][0] = x;
  }
  int cont = 0;
  int out = 0;
  for (int i = 0; i < n; ++i) {
    memset(p, 0, sizeof(p));
    memset(b, 0, sizeof(p));
    p[0] = i;
    for (int j = 0; j < n; ++j) {
      b[j] = num[0][j] ^ p[0];
    }
    for (int j = 0; j < n; ++j) {
      p[j] = num[j][0] ^ b[0];
    }
    int flag = 0;
    for (int j = 0; j < n; ++j) {
      if (p[b[j]] != j || p[j] >= n || b[j] >= n) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cont++;
      if (!out) {
        out = 1;
        memcpy(ans, p, sizeof(int) * (n + 2));
      }
    }
  }
  printf("!\n");
  printf("%d\n", cont);
  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
}
