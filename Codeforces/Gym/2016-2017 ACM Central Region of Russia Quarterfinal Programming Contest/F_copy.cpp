#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int maxn = 1e3 + 100, maxm = 1e6 + 100, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const ll INF = 1e13 + 7;
struct edge {
  int from, to;
  char ch;
};
edge es[maxm];
int pa[maxn];
int findset(int x) { return pa[x] == x ? x : pa[x] = findset(pa[x]); }
void unit(int x, int y) {
  int fx = findset(x), fy = findset(y);
  if (fx <= fy)
    pa[fx] = fy;
  else
    pa[fy] = fx;
}
int in[maxn], out[maxn];
int ans[maxn];
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) pa[i] = i;
  memset(out, 0, sizeof(out));
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= k; i++) {
    scanf("%d%c%d", &es[i].from, &es[i].ch, &es[i].to);
    if (es[i].ch == '=')
      unit(es[i].from, es[i].to);
    else {
      if (es[i].ch == '>') swap(es[i].from, es[i].to);
      es[i].ch = '<';
    }
  }
  for (int i = 1; i <= k; i++) {
    if (es[i].ch == '=') continue;
    out[findset(es[i].from)]++, in[findset(es[i].to)]++;
  }
  for (int i = 1; i <= n; i++)
    if (in[i] && out[i]) ans[i] = 2;
  for (int i = 1; i <= k; i++) {
    if (es[i].ch == '=') continue;
    if (ans[findset(es[i].from)] == 2)
      ans[findset(es[i].to)] = 3;
    else if (ans[findset(es[i].to)] == 2)
      ans[findset(es[i].from)] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (ans[findset(i)] == 1)
      cout << "B";
    else if (ans[findset(i)] == 2)
      cout << "R";
    else if (ans[findset(i)] == 3)
      cout << "W";
    else
      cout << "?";
  }
  cout << endl;
  return 0;
}
