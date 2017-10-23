/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int X[8], Y[8];
const int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
const int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
int manhattan(int x, int y, int x0, int y0) {
  return abs(x - x0) + abs(y - y0);
}
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  for (int i = 0; i < 8; ++i) {
    X[i] = x2 + dx[i];
    Y[i] = y2 + dy[i];
  }
  int d = inf;
  for (int i = 0; i < 8; ++i) {
    d = min(d, manhattan(x1, y1, X[i], Y[i]));
  }
  cout << d * 2 + 8 << '\n';
  return 0;
}
