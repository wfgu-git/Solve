#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

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
inline void out_str(const char *s) {
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


const ll inf = 10000000000000LL;
const int maxn = 100010;
int T, n, m;
int head[maxn], cont, dep[maxn];
struct node {
  int from, to, next;
  ll cap;
} edge[1000000];
void add_edge(int u, int v, ll cap) {
  edge[cont] = (node){u, v, head[u], cap};
  head[u] = cont++;
  edge[cont] = (node){v, u, head[v], 0};
  head[v] = cont++;
}
int BFS(int s, int t) {
  int que[maxn], front = 0, rear = 0;
  memset(dep, -1, sizeof(dep));
  dep[s] = 0;
  que[rear++] = s;
  while (front != rear) {
    int u = que[front++];
    front %= maxn;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].cap > 0 && dep[v] == -1) {
        dep[v] = dep[u] + 1;
        que[rear++] = v;
        rear %= maxn;
        if (v == t) return 1;
      }
    }
  }
  return 0;
}
ll Dinic(int s, int t) {
  ll res = 0;
  while (BFS(s, t)) {
    int Stack[maxn], top, cur[maxn];
    memcpy(cur, head, sizeof(head));
    top = 0;
    int u = s;
    while (1) {
      if (t == u) {
        ll min = inf;
        int loc;
        for (int i = 0; i < top; i++)
          if (min > edge[Stack[i]].cap) {
            min = edge[Stack[i]].cap;
            loc = i;
          }
        for (int i = 0; i < top; i++) {
          edge[Stack[i]].cap -= min;
          edge[Stack[i] ^ 1].cap += min;
        }
        res += min;
        top = loc;
        u = edge[Stack[top]].from;
      }
      for (int i = cur[u]; i != -1; cur[u] = i = edge[i].next)
        if (dep[edge[i].to] == dep[u] + 1 && edge[i].cap > 0) break;
      if (cur[u] != -1) {
        Stack[top++] = cur[u];
        u = edge[cur[u]].to;
      } else {
        if (top == 0) break;
        dep[u] = -1;
        u = edge[Stack[--top]].from;
      }
    }
  }
  return res;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  in(T);
  int s, t;
  for (int cas = 1; cas <= T; ++cas) {
    in(n); in(m);
    in(s); in(t);
    memset(head, -1, sizeof(head));
    cont = 0;
    for (int i = 0; i < m; ++i) {
      int from, to;
      ll cap;
      in(from); in(to); in(cap);
      add_edge(from, to, cap * 200001 + 1);
    }
    ll ans = Dinic(s, t);
    ans %= 200001;
    out_int(ans); out_char('\n');
  }
  write();
  return 0;
}
