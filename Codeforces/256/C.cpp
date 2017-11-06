/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, a[maxn];
int solve(int l, int r, int painted_h) {
  if (l > r) return 0;

  int mn = inf, pos;
  int col = 0;
  for (int i = l; i <= r; ++i) {
    if (mn > a[i]) {
      mn = a[i];
      pos = i;
    }
    if (a[i] > painted_h) {
      col++;
    }
  }
  int row = mn - painted_h;
  return min(col , row + solve(l, pos - 1, mn) + solve(pos + 1, r, mn));
}
void work() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = min(n, solve(1, n, 0));
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
