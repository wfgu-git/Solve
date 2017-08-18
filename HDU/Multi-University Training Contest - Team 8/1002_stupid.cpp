#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int st[maxn + 1];
void Tb() {
  for (int i = 1; i < maxn; ++i) {
    long long ans = 0;
    for (int j = 1; j <= i; ++j) {
      if (__gcd(i, j) == 1) {
        ans += ceil(1.0 * i / (double)j);
      }
    }
    if (i == 100) break;
    st[i] = st[i - 1] + ans;
    cout << st[i] << " ";
  }
}
int main() {
  Tb();
  return 0;
}
