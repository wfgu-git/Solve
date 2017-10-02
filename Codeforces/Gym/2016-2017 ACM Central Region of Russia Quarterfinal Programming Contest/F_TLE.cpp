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
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
struct info {
  int x, t, y;
} ;
vector<info> st;
vector<int> G[maxn];
int vis[maxn];
int ind[maxn];
int ans[maxn];
int dfs(int u, int d) {
  int mx = d;
  for (int v : G[u]) {
    mx = max(mx, dfs(v, d + 1));
  }
  if (d == 2) {
    ans[u] = 0;
  } else if (d == 1 && mx == 2) {
    ans[u] = 1;
  } else if (d == 0 && mx == 2) {
    ans[u] = 2;
  }
  return max(mx, d);
}
int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
  
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  int x, y;
  char opt;
  for (int i = 0; i < m; ++i) {
    scanf("%d%c%d", &x, &opt, &y);
    if (opt == '=') {
      fa[find(y)] = find(x);
    } else {
      if (opt == '<') st.push_back({x, -1, y});
      else st.push_back({x, 1, y});
    }
  }
  for (info q : st) {
    int x = find(q.x);
    int y = find(q.y);
    if (q.t < 0) {
      G[y].push_back(x);
      ind[x]++;
    } else {
      G[x].push_back(y);
      ind[y]++;
    }
  }
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i <= n; ++i) {
    int j = find(i);
    if (vis[j]) continue;
    vis[j] = 1;
    if (ind[j] == 0) {
      dfs(j, 0);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int t = find(i);
    if (ans[t] == -1) putchar('?');
    else if (ans[t] == 0) putchar('B');
    else if (ans[t] == 1) putchar('R');
    else  putchar('W');
  }
  putchar('\n');
}
