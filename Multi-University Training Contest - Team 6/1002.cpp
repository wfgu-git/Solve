  #include <bits/stdc++.h>
using namespace std;

/*
input & out
*/
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext() {
  if (++ps == pe)
    pe = (ps = buf) +
         fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T& ans) {
  ans = 0;
  T f = 1;
  if (ps == pe) return false;  // EOF
  do {
    rnext();
    if ('-' == *ps) f = -1;
  } while (!isdigit(*ps) && ps != pe);
  if (ps == pe) return false;  // EOF
  do {
    ans = (ans << 1) + (ans << 3) + *ps - 48;
    rnext();
  } while (isdigit(*ps) && ps != pe);
  ans *= f;
  return true;
}

const int MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write() {
  fwrite(bufout, sizeof(char), pout - bufout, stdout);
  pout = bufout;
}
inline void out_char(char c) {
  *(pout++) = c;
  if (pout == pend) write();
}
inline void out_str(const char* s) {
  while (*s) {
    *(pout++) = *(s++);
    if (pout == pend) write();
  }
}
template <class T>
inline void out_int(T x) {
  if (!x) {
    out_char('0');
    return;
  }
  if (x < 0) x = -x, out_char('-');
  int len = 0;
  while (x) {
    outtmp[len++] = x % 10 + 48;
    x /= 10;
  }
  outtmp[len] = 0;
  for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
  out_str(outtmp);
}

struct Point {double x, y;};
inline double get_dis(Point& a, Point& b) {return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
inline double get_delta(const double& a, const double& b, const double& c) {return b * b - 4.0 * a * c;}
inline double square(const double& x) {return x * x;}
double c, d, r;

bool check(const double& a, const double& b) {
  double A = (1 - square(a) / square(b));
  double B = -2.0 * d;
  double C = square(a) - square(r) + square(d);
  double delta = get_delta(A, B, C);
  if (delta < 0) return false;

  double x, y;
  y = (-B + sqrt(delta)) * 0.5 / A;
  x = a * a - a * a / (b * b) * y * y;
  if (x >= 0) return true;

  y = (-B - sqrt(delta)) * 0.5 / A;
  x = a * a - a * a / (b * b) * y * y;
  if (x >= 0) return true;

  return false;
}
inline void work() {
  static int tr, px, py, qx, qy;
  in(tr); in(px); in(py); in(qx); in(qy);

  Point p = {1.0 * px, 1.0 * py};
  Point q = {1.0 * qx, 1.0 * qy};
  Point m = {(px + qx) * 0.5, (py + qy) * 0.5};
  Point o = {0, 0};

  c = get_dis(p, q) * 0.5;
  d = get_dis(o, m);
  r = 1.0 * tr;

  double ans = min(2.0 * sqrt(r * r - d * d), 2.0 * sqrt((r - d) * (r - d) + c * c));
  double lb = c; //ub = sqrt((r - d) * (r - d) + c * c);
  double ub = sqrt(r * r - d * d);
  for (int i = 0; i < 50; ++i) {
    double a = (lb + ub) * 0.5;
    double b = sqrt(square(a) - c * c);

    if (check(a, b)) {
      ub = a;
    } else {
      lb = a;
    }
  }
  ans = min(ans, 2.0 * ub);
  out_str(to_string(ans).c_str());
  out_str("\n");
}
int main() {
  // freopen("data.in", "r", stdin);
  int T;
  in(T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  write();
  return 0;
}
