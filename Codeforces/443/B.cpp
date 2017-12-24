/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 500 + 20;

int perm[maxn];
int w[maxn];
list<int> L;
void work() {
  int n;
  ll k;
  cin >> n >> k;
  L.clear();
  for (int i = 1; i <= n; ++i) {
    cin >> perm[i];
    L.push_back(perm[i]);
  }

  if (n <= 2 || k >= n - 1) {
    cout << *max_element(perm + 1, perm + 1 + n) << endl;
    return;
  }

  int mx = 0, winner = 0;
  list<int>::iterator iter, fi, se;
  while (true) {
    iter = L.begin();
    fi = iter;
    ++iter;
    se = iter;

    if (*fi > *se) {
      ++mx;
      L.push_back(*se);
      L.erase(se);
      if (mx >= k) {
        winner = *fi;
        break;
      }
    } else {
      mx = 1;
      L.push_back(*fi);
      L.erase(fi);
    }
  }
  cout << winner << endl;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
