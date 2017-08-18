#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 305;
const int INF = 0x3f3f3f3f;

int love[MAXN][MAXN];  // 记录每个妹子和每个男生的好感度
int ex_girl[MAXN];     // 每个妹子的期望值
int ex_boy[MAXN];      // 每个男生的期望值
bool vis_girl[MAXN];   // 记录每一轮匹配匹配过的女生
bool vis_boy[MAXN];    // 记录每一轮匹配匹配过的男生
int match[MAXN];  // 记录每个男生匹配到的妹子 如果没有则为-1
int slack[MAXN];  // 记录每个汉子如果能被妹子倾心最少还需要多少期望值

int N;

bool dfs(int girl) {
  vis_girl[girl] = true;

  for (int boy = 0; boy < N; ++boy) {
    if (vis_boy[boy]) continue;  // 每一轮匹配 每个男生只尝试一次

    int gap = ex_girl[girl] + ex_boy[boy] - love[girl][boy];

    if (gap == 0) {  // 如果符合要求
      vis_boy[boy] = true;
      if (match[boy] == -1 ||
          dfs(match[boy])) {  // 找到一个没有匹配的男生
                              // 或者该男生的妹子可以找到其他人
        match[boy] = girl;
        return true;
      }
    } else {
      slack[boy] =
          min(slack[boy], gap);  // slack 可以理解为该男生要得到女生的倾心
                                 // 还需多少期望值 取最小值 备胎的样子【捂脸
    }
  }

  return false;
}

int KM() {
  memset(match, -1, sizeof match);  // 初始每个男生都没有匹配的女生
  memset(ex_boy, 0, sizeof ex_boy);  // 初始每个男生的期望值为0

  // 每个女生的初始期望值是与她相连的男生最大的好感度
  for (int i = 0; i < N; ++i) {
    ex_girl[i] = love[i][0];
    for (int j = 1; j < N; ++j) {
      ex_girl[i] = max(ex_girl[i], love[i][j]);
    }
  }

  // 尝试为每一个女生解决归宿问题
  for (int i = 0; i < N; ++i) {
    fill(slack, slack + N, INF);  // 因为要取最小值 初始化为无穷大

    while (1) {
      // 为每个女生解决归宿问题的方法是 ：如果找不到就降低期望值，直到找到为止

      // 记录每轮匹配中男生女生是否被尝试匹配过
      memset(vis_girl, false, sizeof vis_girl);
      memset(vis_boy, false, sizeof vis_boy);

      if (dfs(i)) break;  // 找到归宿 退出

      // 如果不能找到 就降低期望值
      // 最小可降低的期望值
      int d = INF;
      for (int j = 0; j < N; ++j)
        if (!vis_boy[j]) d = min(d, slack[j]);

      for (int j = 0; j < N; ++j) {
        // 所有访问过的女生降低期望值
        if (vis_girl[j]) ex_girl[j] -= d;

        // 所有访问过的男生增加期望值
        if (vis_boy[j]) ex_boy[j] += d;
        // 没有访问过的boy 因为girl们的期望值降低，距离得到女生倾心又进了一步！
        else
          slack[j] -= d;
      }
    }
  }

  // 匹配完成 求出所有配对的好感度的和
  int res = 0;
  for (int i = 0; i < N; ++i) res += love[match[i]][i];

  return res;
}

int main() {
  while (~scanf("%d", &N)) {
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) scanf("%d", &love[i][j]);

    printf("%d\n", KM());
  }
  return 0;
}

/*
二分图最佳匹配 （kuhn munkras 算法 O(m*m*n)).
邻接矩阵形式 。  返回最佳匹配值，传入二分图大小m,n
邻接矩阵 mat ，表示权，match1,match2返回一个最佳匹配,为匹配顶点的match值为-1，
一定注意m<=n，否则循环无法终止，最小权匹配可将全职取相反数。
初始化：  for(i=0;i<MAXN;i++)
             for(j=0;j<MAXN;j++) mat[i][j]=-inf;
对于存在的边：mat[i][j]=val;//注意不能负值
*/
/*
#include <string.h>
#define MAXN 310
#define inf 1000000000
#define _clr(x) memset(x, -1, sizeof(int) * MAXN)
int KM(int m, int n, int mat[][MAXN], int *match1, int *match2) {
  int s[MAXN], t[MAXN], l1[MAXN], l2[MAXN];
  int p, q, i, j, k, ret = 0;
  for (i = 0; i < m; i++) {
    l1[i] = -inf;
    for (j = 0; j < n; j++) l1[i] = mat[i][j] > l1[i] ? mat[i][j] : l1[i];
    if (l1[i] == -inf) return -1;
  }
  for (i = 0; i < n; i++) l2[i] = 0;
  _clr(match1);
  _clr(match2);
  for (i = 0; i < m; i++) {
    _clr(t);
    p = 0;
    q = 0;
    for (s[0] = i; p <= q && match1[i] < 0; p++) {
      for (k = s[p], j = 0; j < n && match1[i] < 0; j++) {
        if (l1[k] + l2[j] == mat[k][j] && t[j] < 0) {
          s[++q] = match2[j];
          t[j] = k;
          if (s[q] < 0) {
            for (p = j; p >= 0; j = p) {
              match2[j] = k = t[j];
              p = match1[k];
              match1[k] = j;
            }
          }
        }
      }
    }
    if (match1[i] < 0) {
      i--;
      p = inf;
      for (k = 0; k <= q; k++) {
        for (j = 0; j < n; j++) {
          if (t[j] < 0 && l1[s[k]] + l2[j] - mat[s[k]][j] < p)
            p = l1[s[k]] + l2[j] - mat[s[k]][j];
        }
      }
      for (j = 0; j < n; j++) l2[j] += t[j] < 0 ? 0 : p;
      for (k = 0; k <= q; k++) l1[s[k]] -= p;
    }
  }
  for (i = 0; i < m; i++) ret += mat[i][match1[i]];
  return ret;
}
*/
