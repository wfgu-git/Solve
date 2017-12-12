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
  int n;
  cin >> n;
  int x, y;
  int x1(0), x2(0);
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    x > 0 ? ++x1 : ++x2;
  }
  if (x1 <= 1 || x2 <= 1) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
