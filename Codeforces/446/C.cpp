/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 2000 + 20;

int n;
int a[maxn];
int g[maxn][maxn];
void work() {
  cin >> n;
  int cnt1 = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt1 += (a[i] == 1);
    g[i][i] = a[i];
  }
  if (cnt1 > 0) {
    cout << n - cnt1;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    int d = a[i];
    for (int j = i + 1; j <= n; ++j) {
      d = __gcd(d, a[j]);
      g[i][j] = d;
    }
  }
  int d = inf;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (g[i][j] == 1) {
        d = min(d, j - i);
      }
    }
  }
  if (d == inf) {
    cout << -1;
    return;
  }
  cout << d + n - 1;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
