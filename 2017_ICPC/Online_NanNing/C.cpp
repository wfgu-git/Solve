/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
int n, m;
struct comp {
  bool operator () (const pii& x, const pii& y) const {
    if (x.first == y.first) {
      return x.second < y.second;
    }
    return x.first > y.first;
  }
} ;
multiset<pii, comp> lot[1000 + 20];
int ans[500 + 20];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      lot[i].clear();
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; ++i) {
      int id, price, reserved;
      cin >> reserved;
      while (true) {
        cin >> id;
        if (id == -1) break;
        cin >> price;
        if (price < reserved) continue;
        lot[i].insert({price, id});
      }
      lot[i].insert({reserved, 666});
      if (lot[i].size() == 1) continue;
      auto iter = lot[i].begin();
      double cost = iter->first;
      int bid = iter->second;
      iter++;
      cost = min(cost, 1.0 * iter->first * 0.1 + (double)(iter->first));
      ans[bid] += (int)cost;
    }
    int Q;
    cin >> Q;
    int id;
    for (int i = 0; i < Q; ++i) {
      cin >> id;
      cout << ans[id] << endl;
    }
  }
}
