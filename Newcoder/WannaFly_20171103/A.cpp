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
  int s, m;
  cin >> s >> m;
  int lb = 0, ub = 1000, mid;
  int ans = -1;
  while (lb < ub - 1) {
    mid = (lb + ub) / 2;

    // check
    int ta = s % mid;
    int tb = mid - ta;
    int x = s / mid + 1;
    int y = s / mid;
    int ret = 0;
    int temp = y;
    for (int i = 1; i < tb; ++i) {
      ret += temp * y;
      temp += y;
    }
    for (int i = 0; i < ta; ++i) {
      ret += temp * x;
      temp += x;
    }
    if (ret >= m) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  cout << (lb == 999 ? -1 : lb) << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
