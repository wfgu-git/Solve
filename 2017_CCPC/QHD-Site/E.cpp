/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

string line;
int check(const string & str) {
  return line.find(str) != line.npos;
}
void work() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n >> line;
    int ans = 0;
    for (int i = 0; i + 3 < n; ++i) {
      if (line[i] == 'C' && line[i + 1] == 'C' && line[i + 2] == 'P' && line[i + 3] == 'C') {
        ans++;
        line[i + 1] = '#';
        line[i + 2] = '#';
      }
    }
    if (check("CCC") || check("CCP") || check("CPC")) ans++;
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
