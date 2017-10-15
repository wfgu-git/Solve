/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

int a[maxn];
int b[maxn];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  int ret = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] == b[j]) {
        ret = min(ret, a[i]);
      }
    }
  }
  if (ret != inf) {
    cout << ret;
    return 0;
  }
  int x = *min_element(a, a + n);
  int y = *min_element(b, b + m);
  if (x > y) swap(x, y);
  if (x == y) cout << x << endl;
  else cout << x << y << endl;
}
