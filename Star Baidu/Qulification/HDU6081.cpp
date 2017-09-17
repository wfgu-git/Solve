/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, m;
int sum[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> m) {
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < m; ++i) {
      int u, v, c;
      cin >> u >> v >> c;
      if (v == u) {
        continue;
      }
      sum[--u] += c;
      sum[--v] += c;
    }
    sort(sum, sum + n);
    cout << sum[0] << endl;
  }
  return 0;
}
