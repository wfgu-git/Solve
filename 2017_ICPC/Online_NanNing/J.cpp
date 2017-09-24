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

const int maxn = 10 + 5;
int a[maxn], b[maxn], arc[maxn];
bool vis[maxn];
int loop[maxn];
int n;
string x, y;
void init() {
  for (int i = 0; i < n; ++i) {
    a[i] = x[i] - '0';
    arc[x[i] - '0'] = i;
  }
  for (int i = 0; i < n; ++i) {
    b[i] = y[i] - '0';
  }
}
void find_loop() {
  memset(vis, 0, sizeof(vis));
  int idx, tot = 0;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      idx = i;
      int len = 0;
      while (!vis[idx]) {
        ++len;
        vis[idx] = 1;
        idx = arc[b[idx]];
      }
      loop[tot++] = len;
    }
  }
  int ans = 0;
  for (int i = 0; i < tot; ++i) {
    if (!i) {
      ans += loop[i] - 1;
    } else {
      ans += loop[i] == 1 ? 0 : loop[i] + 1;
    }
  }
  printf("%d\n", ans);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n) {
    for (int i = 0; i < 5; ++i) {
      cin >> x >> y;
      init();
      find_loop();
    }
  }
  return 0;
}
