/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int pre[maxn], nxt[maxn], pos[maxn];
int a[maxn];
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
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  int T;
  // cin >> T;
  in(T);
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    // cin >> n;
    in(n);
    for (int i = 1; i <= n; ++i) {
      // cin >> a[i];
      in(a[i]);
      pos[a[i]] = i;
      pre[i] = i - 1;
      nxt[i] = i + 1;
    }
    a[n + 1] = inf;
    pre[0] = 0;
    nxt[n] = n + 1;
    int head = 1;
    while (true) {
      int lef = -inf, rig = a[nxt[head]];
      int l = 0, r = nxt[head];
      int cont = 0;
      for (int i = head; i != n + 1; i = nxt[i]) {
        // cout << "pos = " << i << "  pre = " << l << " next = " << r << endl;
        // cout << "lef = " << lef << "  rig = " << rig << endl;
        // cout << "head = " << head << "\n\n";
        if (a[i] < lef || a[i] > rig) {
          ++cont;
          // cout <<"if" << endl;
          nxt[l] = r;
          pre[nxt[i]] = l;
          r = nxt[r];
          if (i == head) {
            head = nxt[head];
          }
        } else {
          // cout <<"else" << endl;
          l = i;
          r = nxt[r];
        }
        lef = a[i];
        rig = a[nxt[nxt[i]]];
      }
      if (!cont) {
        break;
      }
    }
    vector<int> ret;
    for (int i = head; i != n + 1; i = nxt[i]) {
      ret.push_back(a[i]);
    }
    // cout << ret.size() << endl;
    out_int((int)ret.size()); out_char('\n');
    for (int& x : ret)  {
      // cout << x << " ";
      out_int(x); out_char(' ');
    }
    // cout << endl;
    out_char('\n');
  }
  write();
  return 0;
}
