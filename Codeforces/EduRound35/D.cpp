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
  vector<int> perm;
  perm.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> perm[i];
  }

  int cont = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (perm[i] > perm[j]) {
        cont++;
      }
    }
  }
  cont &= 1;

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l; --r;

    int sz = (r - l + 1);
    int k = sz * (sz - 1) / 2;
    if (k & 1) {
      cont ^= 1;
    }

    if (cont & 1) {
      cout << "odd\n";
    } else {
      cout << "even\n";
    }
  }


}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
