/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 400000 + 20;

int n, m, k;
int fa[maxn];
int tot;
bool kick[maxn], vis[maxn];
vector<int> G[maxn];
vector<int> Qs;
int ans[maxn];
int find(int x) {
  if (x != fa[x]) {
    fa[x] = find(fa[x]);
  }
  return fa[x];
}
void add(int x) {
  int p = find(x);
  int q;
  for (int i = 0;i < G[x].size(); ++i) {
    int v = G[x][i];
    if (vis[v]) {
      q = find(v);
      if (p != q) {
        fa[q] = p;
        --tot;
      }
    }
  }
}
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  scanf("%d", &k);
  for (int i=  0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    Qs.push_back(x);
    kick[x] = 1;
  }
}
void work() {
  for (int i = 0; i < n; ++i) {
    fa[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    if (!kick[i]) {
      ++tot;
      add(i);
      vis[i] = 1;
    }
  }
  ans[k] = tot;
  for (int i = k - 1; i >= 0; --i) {
    tot++;
    add(Qs[i]);
    vis[Qs[i]] = 1;
    ans[i] = tot;
  }
  for (int i = 0; i <= k; ++i) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  input();
  work();
}
