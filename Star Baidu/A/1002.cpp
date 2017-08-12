#include <bits/stdc++.h>
using namespace std;

const int MAXBUF = 100000;
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

const int MAXOUT = 100000;
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



const int maxn = 100000 + 20;
struct UFset {
  int n;
  int fa[maxn];
  int rank[maxn];
  set<int> S[maxn];
  inline void init() {
    // this->n = n;
    for (int i = 0; i < maxn; ++i) {
      fa[i] = i;
    }
  }
  inline int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
  }

  inline bool same(int x, int y) {
    return find(x) == find(y);
  }

  inline int unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return 0;
    if (S[x].size() > S[y].size()) swap(x, y);
    for (set<int>::iterator it = S[x].begin(); it != S[x].end(); ++it) {
      S[*it].erase(x);
      S[*it].insert(y);
      S[y].insert(*it);
    }
    fa[x] = y;
    // if (rank[x] < rank[y]) {
    //   fa[x] = y;
    // } else {
    //   fa[y] = x;
    //   if (rank[x] == rank[y]) ++rank[x];
    // }
    /* 统计某个为祖先有几个元素
    fa[y] = x;
    rank[x] += rank[y];
    */
    return 1;
  }
} ufst;
int N;
inline void work() {
  ufst.init();
  vector<int> ans;
  set<int> used;

  int cont = 0;
  int x, y, op;
  for (int i = 0; i < N; ++i) {
    in(x); in(y); in(op);
    ++cont;
    used.insert(x);
    used.insert(y);
    int xrt = ufst.find(x);
    int yrt = ufst.find(y);
    if (op) {
      if (xrt == yrt || !ufst.S[xrt].count(yrt)) {
        ufst.unite(x, y);
      } else {
        ans.push_back(cont);
        cont = 0;
        for (const int& v : used) {
          ufst.S[v].clear();
          ufst.fa[v] = v;
        }
        used.clear();
      }
    } else {
      if (xrt != yrt) {
        ufst.S[xrt].insert(yrt);
        ufst.S[yrt].insert(xrt);
      } else {
        ans.push_back(cont);
        cont = 0;
        for (const int& v : used) {
          ufst.S[v].clear();
          ufst.fa[v] = v;
        }
        used.clear();
      }
    }
  }

  out_int((int)ans.size()); out_char('\n');
  for (const int &x : ans) {
    out_int(x); out_char('\n');
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  in(N);
  work();
  write();
  return 0;
}
