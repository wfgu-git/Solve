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
  string str;
  cin >> str;

  int ans = 0;
  int flag = 0;
  do {
    flag = 0;
    int n = str.size();
    for (int i = 0; i < n - 1; ++i) {
      if (str[i] != str[i + 1]) {
        flag = 1;
        str[i] = str[i + 1] = '.';
        i++;
      }
    }
    if (flag) ++ans;
    str.erase(remove(str.begin(), str.end(), '.'), str.end());
  } while (flag);
  cout << ans;
}
int main() {
  freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
