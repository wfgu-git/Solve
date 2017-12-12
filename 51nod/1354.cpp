/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1000 + 20;
const int moder = 1e9 + 7;

map<ll, ll> mep;
map<ll, ll>::reverse_iterator iter;
ll a[maxn];
void work() {
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    mep.clear();
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      if (k % a[i] != 0) continue;
      for (iter = mep.rbegin(); iter != mep.rend(); ++iter) {
        ll val = a[i] * iter->first;
        if (k % val != 0) continue;
        mep[val] = (mep[val] + iter->second) % moder;
      }
      mep[a[i]] = (mep[a[i]] +  1) % moder;;
    }
    cout << mep[k] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
