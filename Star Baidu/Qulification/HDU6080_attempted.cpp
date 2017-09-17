/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 500 + 20;

struct Point {
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  Point operator - (const Point& rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  double operator * (const Point& rhs) const {
    return x * rhs.y - y * rhs.x;
  }
} ;
Point h[maxn], s[maxn];
int G[maxn][maxn];
void floyd(int n) {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) if (i != k) {
      for (int j = 1; j <= n; ++j) if (i != j && j != k) {
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  while (cin >> n) {
    double x, y;
    for (int i = 1; i <= n; ++i) {
      cin >> x >> y;
      h[i] = {x, y};
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
      cin >> x >> y;
      s[i] = {x, y};
    }
  }
  return 0;
}
