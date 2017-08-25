#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 3005

int a[MAXN], res, n;
int mi[MAXN][MAXN], mx[MAXN][MAXN];
// mi[i][j]表示从i到j的最小值，mx[i][j]表示从i到j的最大值
int f[MAXN][MAXN], r[MAXN];
// f[i][j]表示从i到j可以分成的区间数，r[i]表示最近一次从i开始的区间的右端（方便更新）

void init()  //第一步，分块
{
  memset(mi, 0, sizeof(mi));
  memset(mx, 0, sizeof(mx));
  memset(f, 0, sizeof(f));
  memset(r, 0, sizeof(r));
  for (int i = 1; i <= n; i++) {
    mi[i][i] = a[i];
    mx[i][i] = a[i];
    f[i][i] = 1;
    r[i] = i;
  }
  //为mi,mx赋值
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      mx[i][j] = max(a[j], mx[i][j - 1]);
      mi[i][j] = min(a[j], mi[i][j - 1]);
    }
  //为f数组赋值
  for (int t = 2; t <= n; t++)  // t在枚举区间长度
    for (int i = 1; i + t - 1 <= n; i++) {
      int j = i + t - 1;
      //不是连续的一段无法分区间
      if (mx[i][j] - mi[i][j] != t - 1)
        f[i][j] = 0;
      else {
        // j一定大于r[i]
        if (mi[i][r[i]] > mi[i][j])
          f[i][j] = 1;
        else
          f[i][j] = f[i][r[i]] + f[r[i] + 1][j];
        r[i] = j;  //这个r数组很精华
      }
    }
}

void solve()  //第二步，枚举找交换区间
{
  int k;
  res = max(1, f[1][n]);  // WA点，一开始写成res=1就WA了
  //先枚举seg_a
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      //满足条件才能继续枚举seg_b
      if (i == 1 || (f[1][i - 1] != 0 && mi[1][i - 1] == 1)) {
        k = mx[i][j];
        if (f[i][j] && (k == n || (f[k + 1][n] != 0 && mx[k + 1][n] == n))) {
          for (int t = j + 1; t <= k; t++) {
            if (f[t][k] && mi[t][k] == i) {
              // printf("%d %d %d %d
              // %d\n",i,j,t,k,f[1][i-1]+1+f[j+1][t-1]+1+f[k+1][n]);
              res =
                  max(res, f[1][i - 1] + 1 + f[j + 1][t - 1] + 1 + f[k + 1][n]);
            }
          }
        }
      }
    }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    init();
    solve();
    printf("%d\n", res);
  }
  return 0;
}
