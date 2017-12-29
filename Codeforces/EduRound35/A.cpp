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
  map<int, vector<int> > mep;

  int mn = inf;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!mep.count(x)) {
      mep[x] = vector<int>();
    }
    mep[x].push_back(i);
    mn = min(mn, x);
  }

  int ans = inf;
  vector<int> & v = mep[mn];
  int sz = v.size();
  for (int i = 1; i < sz; ++i) {
    ans = min(ans, v[i] - v[i - 1]);
  }
  cout << ans;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
