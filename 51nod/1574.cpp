/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 200000 + 20;

int a[maxn];
void work() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a[x] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      if (a[x] >= i) {
        ans += (ll)a[x] - (ll)i;
      }
    }
    cout << ans << endl;
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
  // data();
}
