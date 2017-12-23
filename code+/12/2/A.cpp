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

int Lcount[100], Rcount[100];
void work() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;

    int l = str.size();
    if (str[l - 1] >= 'A' && str[l - 1] <= 'Z') {
      str.push_back('1');
    }
    int f = 1;
    while (f) {
      f = 0;
      l = str.size();
      for (int i = 0; i < l; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          if (i + 1 < l && !(str[i + 1] >= '0' && str[i + 1] <= '9')) {
            f = 1;
            str.insert(i + 1, "1");
          }
        }
      }
    }

    int idx = (int)str.find("=");
    int flag = 0;
    for (int i = 0; i < idx; ++i) {
      if (str[i] == '=') {
        flag = -1;
        continue;
      }
      if (str[i] >= 'A' && str[i] <= 'Z') {
        if (i + 1 < idx && str[i + 1] >= '0' && str[i + 1] <= '9') {
          Lcount[str[i] - 'A'] += str[i + 1] - '0';
        }
      }
    }
    for (int i = idx + 1; i < l; ++i) {
      if (str[i] == '=') {
        flag = 1;
        continue;
      }
      if (str[i] >= 'A' && str[i] <= 'Z') {
        if (i + 1 < l && str[i + 1] >= '0' && str[i + 1] <= '9') {
          Rcount[str[i] - 'A'] += str[i + 1] - '0';
        }
      }
    }
    

    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
