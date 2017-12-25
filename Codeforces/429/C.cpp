/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 200000 + 20;

int a[maxn], ans[maxn];
struct B {
  int pos, val;

  bool operator < (const B & rhs) const {
    return val < rhs.val;
  }
} b[maxn];
void work() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    b[i] = {i, x};
  }

  sort(b + 1, b + 1 + n);
  sort(a + 1, a + 1 + n);
  reverse(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) {
    ans[b[i].pos] = a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
