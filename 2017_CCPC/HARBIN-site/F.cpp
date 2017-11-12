/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

vector<int> ans;
void work() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ans.resize(n);
    int now = 0;
    for (int i = 0;i < n; i += 2) {
      ans[i] = ++now;
    }
    for (int i = 1; i < n; i += 2) {
      ans[i] = ++now;
    }
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        cout << ans[i];
        continue;
      }
      cout << " " << ans[i];
      if (i + 1 == n) cout << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
