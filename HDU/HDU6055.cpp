#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 20;
using pii = pair<int, int>;
int tot;
struct Edge {
  pii mid, dir;
  int val;
  int u, v;
  bool operator < (const Edge &rhs) const {
    if (mid.first == rhs.mid.first && mid.second == rhs.mid.second) {
      return val < rhs.val;
    }
    return mid.first * 1000 + mid.second < rhs.mid.first * 1000 + rhs.mid.second;
  }
} edge[maxn * maxn];
int x[maxn], y[maxn];
int ans;
void solve(int l, int r) {
  for (int i = l; i < r - 1; i++) {
    for (int j = i + 1; j < r; j++) {
      pii d1 = edge[i].dir;
      pii d2 = edge[j].dir;
      if (d1.first * d2.first + d1.second * d2.second == 0) ++ans;
    }
  }
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    tot = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", x + i, y + i);
    }
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        edge[tot].dir = {x[j] - x[i], y[j] - y[i]};
        edge[tot].val = {(x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i])};
        edge[tot].u = i, edge[tot].v = j;
        edge[tot++].mid = {x[i] + x[j], y[i] + y[j]};
      }
    }
    sort(edge, edge + tot);
    ans = 0;
    int l = 0, r = 0;
    int val, mm;
    val = edge[l].val, mm = edge[l].mid.first * 1000 + edge[l].mid.second;
    while (r < tot) {
      // cout << r << endl;
      if(edge[r].val == val && edge[r].mid.first * 1000 + edge[r].mid.second == mm){
        r++;
      }else{
        if(r - 1 > l) solve(l, r);
        l = r;
        val = edge[l].val, mm = edge[l].mid.first * 1000 + edge[l].mid.second;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
