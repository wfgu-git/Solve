#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
const int maxq = 100000;
int a[maxn * 2 + 1];
int ans[maxq + 1];
map < int, vector < pair < int, int > > > qry;
map < int, vector < int > > ai;
set < int > kk;
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
    int n, m;
    scanf("%d%d", &n, &m);
    for_each(a, a + n, [](int &x) {scanf("%d", &x);});
    qry.clear();
    kk.clear();
    for (int i = 0; i < m; i++) {
      int k, s;
      scanf("%d%d", &k, &s);
      qry[k].push_back({s, i});
      kk.insert(k);
    }
    ai.clear();
    for (auto x : kk) {
      int d = 0;
      while (x * d < n) {
        ai[x].push_back(a[x * d]);
        d++;
      }
      sort(ai[x].begin(), ai[x].end());
      reverse(ai[x].begin(), ai[x].end());
    }
    for (auto kv : qry) {
      int k = kv.first;
      for (auto _pair : qry[k]) {
        int now = _pair.second;
        int s = _pair.first;
        if (s - 1 >= ai[k].size()) ans[now] = -1;
        else ans[now] = (ai[k])[s - 1];
      }
    }
    for (int i = 0; i < m; i++) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
