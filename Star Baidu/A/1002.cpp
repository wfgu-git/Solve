#include <bits/stdc++.h>
using namespace std;
const int maxm = 100000;
const int maxn = maxm * 2 + 20;


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


struct UFset {
  int n;
  int fa[maxn], rank[maxn];
  inline void init() {
    // this->n = n;
    for (int i = 0; i < maxn; ++i) {
      rank[i] = 0;
      fa[i] = i;
    }
  }
  inline int find(int x) {
    if (x != fa[x]) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }
  inline int unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return 0;

    if (rank[a] < rank[b]) {
      fa[a] = b;
    } else {
      fa[b] = a;
      if (rank[a] == rank[b]) ++rank[a];
    }
    /* 统计某个为祖先有几个元素
    fa[b] = a;
    rank[a] += rank[b];
    */
    return 1;
  }
  inline bool same(int a, int b) {return find(a) == find(b);}
} st;
int L;
inline void work() {
  st.init();
  for (int i = 0; i < L; ++i) {
    static int u, v, k;
    scanf("%d%d%d", &u, &v, &k);
    if (k) {
      if (same())
    } else {

    }
  }
}
int main() {
  while (scanf("%d", &L) != EOF) {
    work();
  }
  return 0;
}
