/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const double pi = acos(-1.0);

int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/solve/data.out", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--) {
    double r, theta;
    scanf("%lf%lf", &r, &theta);
    double rad = theta / 180.0 * pi;
    double S1 = 0.5 * r * r * sin(rad);
    double S2 = theta / 360.0 * pi * r * r;
    printf("%.6lf\n", S2 - S1);
  }
}
