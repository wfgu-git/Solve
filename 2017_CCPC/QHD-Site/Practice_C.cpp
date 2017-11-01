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
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int t = n / m;
    int r = n % m;
    vector<int> ans;
    for (int i = 1; i <= r; ++i) {
      for (int j = 0; j < t + 1; ++j) {
        ans.push_back(i);
      }
    }
    for (int i = r + 1; i <= m; ++i) {
      for (int j = 0; j < t; ++j) {
        ans.push_back(i);
      }
    }
    int fi = 1;
    for (int x : ans) {
      if (fi) {
        fi = 0;
        cout << x;
        continue;
      }
      cout << " " << x;
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
