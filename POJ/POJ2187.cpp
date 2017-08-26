/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 50000 + 20;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;

double add(const double& a, const double& b) {
  if (fabs(a + b) < eps * (fabs(a) + fabs(b))) return 0;
  return a + b;
}
struct Point {
  double x, y;

  bool operator < (const Point& rhs) const {
    if (x != rhs.x) return x < rhs.x;
    return y < rhs.y;
  }
  Point operator + (const Point& rhs) const {
    return (Point){add(x, rhs.x), add(y, rhs.y)};
  }
  Point operator - (const Point& rhs) const {
    return (Point){add(x, -rhs.x), add(y, -rhs.y)};
  }
  Point operator * (const double& d) const {
    return (Point){x * d, y * d};
  }
  double dot(const Point& rhs) const { // 内积
    return add(x * rhs.x, y * rhs.y);
  }
  double det(const Point& rhs) const {
    return add(x * rhs.y, -y * rhs.x);
  }
  double dist_square(const Point& rhs) const {
    return (*this - rhs).dot(*this - rhs);
  }
} ;
vector<Point> convex_hull(Point *ps, int n) {
  sort(ps, ps + n);
  int k = 0;
  vector<Point> qs(n * 2);
  for (int i = 0; i < n; ++i) {
    while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; --i) {
    while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

int N;
Point ps[maxn];
void work() {
  double x, y;
  int tx, ty;
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", &tx, &ty);
    ps[i] = {x = 1.0 * tx, y = 1.0 * ty};
  }
  vector<Point> qs = convex_hull(ps, N);
  double ans = 0;
  for (int i = 0; i < qs.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      ans = max(ans, qs[i].dist_square(qs[j]));
    }
  }
  printf("%.0f\n", ans);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d", &N) != EOF) {
    work();
  }
  return 0;
}
