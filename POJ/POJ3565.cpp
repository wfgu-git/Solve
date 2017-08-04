#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps = 1e-7;
const int maxn = 100 + 20;
const double inf = 1e10;
void debug() {printf("!!!!!!!!\n");}
struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  void read() {
    scanf("%d%d", &x, &y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  double operator * (const Point &rhs) const {
    Point a(*this - rhs);
    return hypot(1.0 * a.x, 1.0 * a.y);
  }
} ;
Point white[maxn];
Point black[maxn];
int n;
double love[maxn][maxn];
double ex_girl[maxn];
double ex_boy[maxn];
bool vis_girl[maxn];
bool vis_boy[maxn];
int match[maxn];
double slack[maxn];
bool dfs(int girl) {
  vis_girl[girl] = true;
  for (int boy = 1; boy <= n; ++boy) {
    if (vis_boy[boy]) continue;
    double gap = ex_girl[girl] + ex_boy[boy] - love[girl][boy];
    if (fabs(gap) < eps) {
      vis_boy[boy] = true;
      if (match[boy] < 0 || dfs(match[boy])) {
        match[boy] = girl;
        return true;
      }
    } else {
      slack[boy] = min(slack[boy], gap);
    }
  }
  return false;
}
void KM() {
  memset(match, -1, sizeof(match));
  memset(ex_boy, 0, sizeof(ex_boy));
  for (int i = 1; i <= n; ++i) {
    ex_girl[i] = love[i][1];
    for (int j = 2; j <= n; ++j) {
      ex_girl[i] = max(ex_girl[i], love[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i) {
    fill(slack + 1, slack + n + 1, inf);
    // memset(slack, 0x3f, sizeof(slack));
    while (true) {
      memset(vis_girl, 0, sizeof(vis_girl));
      memset(vis_boy, 0, sizeof(vis_boy));
      if (dfs(i)) break;
      double d = inf;
      for (int j = 1; j <= n; ++j) {
        if (!vis_boy[j]) d = min(d, slack[j]);
      }
      for (int j = 1; j <= n; ++j) {
        if (vis_girl[j]) ex_girl[j] -= d;
        if (vis_boy[j]) ex_boy[j] += d;
        else slack[j] -= d;
      }
    }
  }
  // debug();
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", match[i]);
  }
}
int main() {
  int kase = 0;
  while (scanf("%d", &n) != EOF) {
    if (kase++) puts("");
    for (int i = 1; i <= n; ++i) white[i].read();
    for (int i = 1; i <= n; ++i) black[i].read();
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        love[j][i] = -(white[i] * black[j]);
      }
    }
    KM();
  }
  return 0;
}
