/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int digit_sum(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> ans;
  if (n >= 81) {
    for (int i = n - 81; i <= n; ++i) {
      if (i + digit_sum(i) == n) {
        ans.push_back(i);
      }
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
      cout << x << '\n';
    }
    return 0;
  }
  for (int i = 0; i <= n; ++i) {
    if (i + digit_sum(i) == n) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x << '\n';
  }
  return 0;
}
