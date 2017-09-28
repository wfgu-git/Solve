/*
教练我想打ACM！
*/
// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const double eps = 0.01;
const double PI = acos(-1.0);

double dgcd(double x, double y) {
  if (x < eps) return y;
  if (y < eps) return x;
  return dgcd(y, fmod(x, y)); // x % y
}
int main() {
  double x[3], y[3], l[3];
  for (int i = 0; i < 3; ++i) {
    scanf("%lf%lf", x + i, y + i);
  }
  double a, b, c;
  c = sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]));
  b = sqrt((x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]));
  a = sqrt((x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]));
  double s = (a + b + c) / 2.0;
  double S = sqrt(s * (s - a) * (s - b) * (s - c));
  double r = a * b * c / S / 4.0;
  double A, B, C;
  A = acos(1 - (a * a / (2.0 * r * r)));
  B = acos(1 - (b * b / (2.0 * r * r)));
  C = 2.0 * PI - A - B;
  double g = dgcd(C, dgcd(A, B));
  // g = dgcd(g, C);
  double ans = r * r * sin(g) * PI / g;
  printf("%.6lf\n", ans);
}
