/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

int fa[maxn];
int out[maxn], in[maxn];
struct Edge {
  int from, to;
  char ch;
} edge[maxn * maxn];
int trace(int x) {
  return x == fa[x] ? x : fa[x] = trace(fa[x]);
}
void unite(int x, int y) {
  if ((x = trace(x)) == (y = trace(y))) {
    return;
  }
  fa[x] = y;
}
int ans[maxn];
int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  memset(out, 0, sizeof(out));
  memset(in, 0, sizeof(in));
  for (int i = 0; i < m; ++i) {
    int x, y;
    char t;
    scanf("%d%c%d", &x, &t, &y);
    edge[i] = {x, y, t};
    if (t == '=') {
      unite(x, y);
    } else {
      if (t == '>') swap(edge[i].from, edge[i].to);
      edge[i].ch = '<';
    }
  }
  for (int i = 0; i < m; ++i) {
    if (edge[i].ch == '=') continue;
    out[trace(edge[i].from)]++;
    in[trace(edge[i].to)]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (in[i] && out[i]) {
      ans[i] = 2;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (edge[i].ch == '=') continue;
    if (ans[trace(edge[i].from)] == 2) {
      ans[trace(edge[i].to)] = 3;
    } else if (ans[trace(edge[i].to)] == 2) {
      ans[trace(edge[i].from)] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int t = ans[trace(i)];
    if (t == 1) {
      putchar('B');
    } else if (t == 2) {
      putchar('R');
    } else if (t == 3) {
      putchar('W');
    } else {
      putchar('?');
    }
  }
  puts("");
}
