/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

char grid[9][9];
int x, y;
void work() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; j += 3) {
      scanf("%s", grid[i] + j);
    }
  }
  scanf("%d%d", &x, &y);

  int nx = ((x % 3) - 1 + 3) % 3;
  int ny = ((y % 3) - 1 + 3) % 3;
  nx *= 3;
  ny *= 3;
  // printf("(%d, %d)\n", nx, ny);
  int flag = 0;
  for (int i = nx; i < nx + 3; ++i) {
    for (int j = ny; j < ny + 3; ++j) {
      if (grid[i][j] == '.') {
        flag = 1;
        grid[i][j] = '!';
      }
    }
  }
  if (!flag) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (grid[i][j] == '.') {
          grid[i][j] = '!';
        }
      }
    }
  }
  for (int i = 0; i < 9; ++i) {
    if (i && i % 3 == 0) {
      printf("\n");
    }
    for (int j = 0; j < 9; ++j) {
      if (j == 3 || j == 6) {
        printf(" ");
      }
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}
int main() {
  // freopen("data.in", "r", stdin);

  work();
}
