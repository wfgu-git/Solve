#include <bits/stdc++.h>
using namespace std;
const int maxr = 100 + 20;
int star[maxr][maxr][10 + 5];
int main() {
  int n, q, c;
  scanf("%d%d%d", &n, &q, &c);
  for (int i = 0; i < n; ++i) {
    static int x, y, s;
    scanf("%d%d%d", &x, &y, &s);
    star[x][y][s]++;
  }
  for (int r = 1; r <= 100; ++r) {
    for (int c = 1; c <= 100; ++c) {
      for (int k = 0; k <= 10; ++k) {
        star[r][c][k] += (star[r - 1][c][k] + star[r][c - 1][k] - star[r - 1][c - 1][k]);
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    long long ans = 0;
    int t, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    for (int k = 0; k <= 10; ++k) {
      long long temp = (star[x2][y2][k] - star[x1 - 1][y2][k] - star[x2][y1 - 1][k] + star[x1 - 1][y1 - 1][k]) * ((t + k) % (c + 1));
      ans += temp;
    }
    cout << ans << endl;
  }
  return 0;
}
