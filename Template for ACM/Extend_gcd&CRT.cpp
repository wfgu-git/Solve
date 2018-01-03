ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll d = extend_gcd(b, a % b, x, y);
  ll t = x; x = y; y = t - a / b * y;
  return d;
}

int crt(int *a, int *m, int n) {
  int M = 1;
  for (int i = 0; i < n; i++) M *= m[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    int Mi = M / m[i];
    extend_gcd(Mi, m[i], x, y);
    ans = (ans + Mi * x * a[i]) % M;
  }
  if (ans < d) ans += M;
  return ans;
}

#include <iostream>

int gcd(int x, int y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}

int extend_gcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int d = extend_gcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}

int main() {
  /*
  ax + by = c;
  */
  int a, b, c;
  while (std::cin >> a >> b >> c) {
    int g = gcd(a, b);
    if (c % g != 0) {
      std::cout << "no" << std::endl;
      continue;
    }
    int k = c / g;
    int x0, y0;
    extend_gcd(a, b, x0, y0);
    // special
    int x = x0 * k;
    int y = y0 * k;
    std::cout << "x = " << x << ", y =  " << y << std::endl;

    /* normal
    ansx += b / g * t;
    ansy -= a / g * t;
    */
  }
}
