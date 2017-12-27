/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

void work() {
  int n, m;
  cin >> n >> m;

  int cont[100 + 20];
  memset(cont, 0, sizeof(cont));
  for (int i = 1; i <= m; ++i) {
    int temp = -1, idx = 0;
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      if (temp < x) {
        temp = x;
        idx = j;
      }
    }
    ++cont[idx];
    // cout << idx << "  " << cont[idx] << endl;
  }

  int ans = 0;
  cont[ans] = 0;
  for (int i = 1; i <= n; ++i) {
    if (cont[ans] < cont[i]) {
      ans = i;
    }
  }
  cout << ans;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
