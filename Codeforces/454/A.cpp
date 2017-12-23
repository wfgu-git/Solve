/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

void work() {
  int v1, v2, v3, vm;
  int flag = 1;
  cin >> v1 >> v2 >> v3 >> vm;
  if (vm > v3 * 2 || v3 > vm * 2) {
    flag = 0;
  }
  int z = max(v3, vm);
  int y = max(v2, 2 * z + 1);
  int x = max(v1, y + 1);
  if (y > 2 * v2 || x > 2 * v1) {
    flag = 0;
  }
  if (!flag) {
    cout << -1;
    return;
  }
  cout << x << "\n" << y << "\n" << z;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
