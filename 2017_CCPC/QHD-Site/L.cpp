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
  string line;
  while (T--) {
    int n, m;
    cin >> n >> m;
    cin >> line;
    int x = 0, y = 0;
    for (int i = 1; i <= m - 1; ++i) {
      if (line[i] == 'R') {
        x++;
      }
    }
    for (int i = m - 1; i < n - 1; ++i) {
      if (line[i] == 'L') {
        y++;
      }
    }
    cout << min(x, y) << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  work();
}
