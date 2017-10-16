/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int a[3];
int used[3];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  int n, a, b, c;
  cin >> n;
  cin >> a >> b >> c;
  --n;
  int ans = 0;
  if (n) {
    if (c >= min(a, b)) {
      ans = n * min(a, b);
    } else {
      ans = min(a, b) + (n - 1) * c;
    }
  }
  cout << ans;
}
