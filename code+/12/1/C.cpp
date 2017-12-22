/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 20;

int A, B;
char S[maxn], T[maxn];
int dp[maxn][maxn][2][2];
char charList[] = {'A', 'T', 'G', 'C'};
int d[4][4];
int getid(char ch) {
  if (ch == 'A') {
    return 0;
  }
  if (ch == 'T') {
    return 1;
  }
  if (ch == 'G') {
    return 2;
  }
  if (ch == 'C') {
    return 3;
  }
}
void work() {
  scanf("%s%s", S + 1, T + 1);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int val;
      scanf("%d", &val);
      int x = getid(charList[i]);
      int y = getid(charList[j]);
      d[x][y] = val;
    }
  }
  scanf("%d%d", &A, &B);

  int n = strlen(S + 1);
  int m = strlen(T + 1);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int p = 0; p < 2; ++p) {
        for (int q = 0; q < 2; ++q) {
          dp[i][j][p][q] = -inf;
        }
      }
    }
  }

  dp[0][0][0][0] = 0;
  dp[1][0][0][1] = -A;
  dp[0][1][1][0] = -A;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int p = 0; p < 2; ++p) {
        for (int q = 0; q < 2; ++q) if (p != 1 || q != 1) {
          int s = getid(S[i]);
          int t = getid(T[j]);
          dp[i][j][0][0] = max(dp[i][j][0][0], dp[i - 1][j - 1][p][q] + d[s][t]);
          dp[i][j][0][1] = max(dp[i][j][0][1], dp[i - 1][j][p][q] - (q ? B : A));
          dp[i][j][1][0] = max(dp[i][j][1][0], dp[i][j - 1][p][q] - (p ? B : A));
        }
      }
    }
  }
  printf("%d\n", max(dp[n][m][0][0], max(dp[n][m][0][1], dp[n][m][1][0])));
}

int main() {
  // freopen("data.in", "r", stdin);

  work();
}

/*
ATGG
ATCC
5 -4 -4 -4
-4 5 -4 -4
-4 -4 5 -4
-4 -4 -4 5
2 1
*/
