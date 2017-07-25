#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int kase = 0;
  int n;
  while (cin >> n) {
    int ans = floor(n * log(2.0) / log(10.0));
    printf("Case #%d: %d\n", ++kase, ans);
  }
}
