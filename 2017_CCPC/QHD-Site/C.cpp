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
  string raw;
  while (T--) {
    cin >> raw;
    int ans = 0;
    vector<char> S{'a', 'g', 'o'};
    do {
      int now = 0;
      string str = raw;
      for (int i = 0; i < 3; ++i) {
        int flag = 0;
        string t(3, (char)S[i]);
        if (str.find(t) != str.npos) {
          flag = 1;
        }
        str.erase(remove(str.begin(), str.end(), S[i]), str.end());
        now += flag;
      }
      ans = max(ans, now);
    } while (next_permutation(S.begin(), S.end()));
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
