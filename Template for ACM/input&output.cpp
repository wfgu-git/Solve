#include <bits/stdc++.h>
using namespace std;
// // 普通版
// template<class T> inline bool read(T &n){
//     T x = 0, tmp = 1;
//     char c = getchar();
//     while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
//     if(c == EOF) return false;
//     if(c == '-') c = getchar(), tmp = -1;
//     while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
//     n = x*tmp;
//     return true;
// }
// template <class T> inline void write(T n){
//     if(n < 0){putchar('-');n = -n;}
//     int len = 0,data[20];
//     while(n){data[len++] = n%10;n /= 10;}
//     if(!len) data[len++] = 0;
//     while(len--) putchar(data[len]+48);
// }
//
// 加强版
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

int main() {
  int t, ca = 1;
  in(t);
  while (t--) {
    int n;
    in(n);

    out_str("Case #");
    out_int(ca++);
    out_str(": ");
    out_int(n), out_char('\n');
  }
  write();  // 一定要记得 write()啊！！！！！
  return 0;
}
