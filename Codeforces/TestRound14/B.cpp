/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

void work() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> perm {0, 1, 2, 3, 4, 5};
  int V[] = {a, a, a, a, b, b};
  int ans = inf;
  do {
    int temp = 1, left = n;

    for (int i : perm) {
      int x = V[i];
      if (left >= x) {
        left -= x;
      } else {
        ++temp;
        left = n - x;
      }
    }
    ans = min(ans, temp);
  } while (next_permutation(perm.begin(), perm.end()));
  cout << ans;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
