#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 20;
struct Point {
  double x, y;
  double dist(const Point& rhs) const {
    return hypot(x - rhs.x, y - rhs.y);
  }
  double operator * (const Point& rhs) const {
    return
  }
  bool operator < (const Point& rhs) const {

  }
} p[maxn];
int N;
inline void work() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    static int tx, ty;
    static double x, y;
    scanf("%d%d", &tx, &ty);
    x = tx; y = ty;
    p[i] = {x, y};
  }
  sort(p + 1, p + 1 + N);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
