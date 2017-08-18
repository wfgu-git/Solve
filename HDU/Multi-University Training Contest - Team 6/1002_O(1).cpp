#include <bits/stdc++.h>
using namespace std;

const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext() {
  if (++ps == pe)
    pe = (ps = buf) +
         fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T &ans) {
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
inline void out_str(char *s) {
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

struct Point {
	double x, y;
} ;
double get_dis(Point& a, Point& b) {
	return hypot(a.x - b.x, a.y - b.y);
}
int R, px, py, qx, qy;
void work() {
	in(R); in(px); in(py); in(qx); in(qy);
	Point P = {1.0 * px, 1.0 * py};
	Point Q = {1.0 * qx, 1.0 * qy};
	Point O = {0, 0};
	Point M = {(P.x + Q.x) * 0.5, (P.y + Q.y) * 0.5};
	double PQ = get_dis(P, Q);
	double d = get_dis(O, M);
	double c = get_dis(M, P);
	double b = get_dis(O, P);

	double ans;
	if (R * d < b * b) {
		ans = 2.0 * c *R / b;
	} else {
		ans = 2.0 * sqrt(c * c + (R - d) * (R - d));
	}
	out_str(to_string(ans).c_str());
	out_str("\n");
}
int main() {
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		work();
	}
	write();
	return 0;
}
