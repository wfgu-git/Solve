/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1000000 + 20;

void work() {
  int n;
  cin >> n;

  ll sum = 0;
  int flag = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x & 1) {
      flag = 0;
    }
    sum += x;
  }
  if (flag) {
    cout << "Second";
  } else {
    cout << "First";
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
