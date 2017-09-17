#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int N = 500 + 3;

int n, m;
int mat[N][N];
int dist[N];
int visited[N];
int del[N];  // true表示该点已经被删掉

// 结点~n
int Stoer_Wagner()
{
     int minCut = INT_MAX;  // 无向图最小割
     int tmp;
     int i, t, j, k, pre;
     int s = 1;   // 源点
     memset(del, 0, sizeof(del));

     for (t = 1; t < n; t++)  // n - 1次Maximum Adjacency Search
     {
         for (i = 1; i <= n; i++)
              if (!del[i])
                   dist[i] = mat[s][i];

         memset(visited, 0, sizeof(visited));
         visited[s] = 1;
         k = s;
         for (i = 1; i <= n - t; i++)  // 每次剩下n - t + 1个结点
         {
              tmp = -1e9;
              pre = k;
              k = 0;
              for (j = 1; j <= n; j++)
              {
                   if (!del[j] && !visited[j] && dist[j] > tmp)
                   {
                       k = j;
                       tmp = dist[j];
                   }
              }
              if (!k) return 0;  // 不连通

              visited[k] = 1;
              for (j = 1; j <= n; j++)
                   if (!del[j] && !visited[j])
                       dist[j] += mat[k][j];
         }

         minCut = min(minCut, dist[k]);
         del[k] = 1;  // 删除k点

         // 合并k点和源点

         for (i = 1; i <= n; i++)
              if (!del[i] && i != pre)
              {
                   mat[pre][i] += mat[k][i];
                   mat[i][pre] = mat[pre][i];
              }
     }

     return minCut;
}

int main ()
{
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
     int u, v, w, i;
     while (scanf("%d%d", &n, &m) != EOF)
     {
         memset(mat, 0, sizeof(mat));
         while (m--)
         {
              scanf("%d%d%d", &u, &v, &w);
              if (u == v) continue;
              mat[u + 1][v + 1] += w;
              mat[v + 1][u + 1] += w;
         }
         printf("%d\n", Stoer_Wagner());
     }
}
