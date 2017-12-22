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

vector<int> num;
void work() {
  int rmax = 1000000000;
  int up = sqrt(rmax);
  for (int i = 0; i <= up; ++i) {
    int j = i * i;
    num.push_back(j);
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    int a = lower_bound(num.begin(), num.end(), l) - num.begin() + 1;
    int b = lower_bound(num.begin(), num.end(), r) - num.begin() + 1;
    int ans = b - a;
    int t = sqrt(r);
    if (t * t == r) ++ans;
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
