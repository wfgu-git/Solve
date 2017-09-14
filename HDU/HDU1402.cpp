/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;
const double pi = acos(-1.0);

struct Complex {
  double r, i;
  Complex(double _r = 0,double _i = 0) : r(_r), i(_i) {}
  Complex operator + (const Complex& rhs) const {
    return Complex(r + rhs.r, i + rhs.i);
  }
  Complex operator - (const Complex& rhs) const {
    return Complex(r - rhs.r, i - rhs.i);
  }
  Complex operator * (const Complex& rhs) const {
    return Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r);
  }
} ;
int A[maxn], B[maxn];
int C[maxn];
int main() {
  string a, b;
  while (cin >> a >> b) {

  }
  return 0;
}
