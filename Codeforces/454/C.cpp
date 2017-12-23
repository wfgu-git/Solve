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
  int n;
  cin >> n;
  int temp[26], valid[26];
  for (int i = 0; i < 26; ++i) {
    valid[i] = 1;
  }
  string mode, word;
  int ans = 0, now = 26;
  for (int i = 0; i < n; ++i) {
    cin >> mode >> word;
    if (i == n - 1) {
      break;
    }
    if (mode[0] == '.') {
      for (char & ch : word) {
        int k = ch - 'a';
        if (valid[k]) {
          valid[k] = 0;
          --now;
        }
      }
    } else if (mode[0] == '!') {
      if (now == 1) {
        ++ans;
      } else {
        memset(temp, 0, sizeof(temp));
        for (char & ch : word) {
          int k = ch - 'a';
          temp[k] = 1;
        }
        for (int i = 0; i < 26; ++i) {
          if (!temp[i] && valid[i]) {
            valid[i] = 0;
            --now;
          }
        }
      }
    } else {
      if (now == 1) {
        ++ans;
      } else {
        for (char & ch : word) {
          int k = ch - 'a';
          if (valid[k]) {
            valid[k] = 0;
            --now;
          }
        }
      }
    }
  }
  cout << ans;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
