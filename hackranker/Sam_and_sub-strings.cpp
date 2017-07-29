#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int moder = 1e9 + 7;
int main() {
  string str;
  while (cin >> str) {
    int slen = str.size();

    /*
    st[0] = s[0];
    st[i] = (i + 1) * s[i] + 10 * st[i - 1];
    ans = \sum {st[0]...st[n - 1]}
    */

    ll ans = 0;
    ll temp = 0;
    for (int i = 0; i < slen; ++i) {
      temp = (1LL * temp * 10 + 1LL * (i + 1) * (str[i] - '0')) % moder;
      ans = (ans + temp) % moder;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
