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

int vis[maxn];
void work() {
  int a, b, c;
  cin >> a >> b >> c;
  int p = 0;
  int r = a % b;
  int t = a / b;
  for ( ; ; ) {
    ++p;
    a = r * 10;
    r = a % b;
    t = a / b;
    if (t == c) {
      cout << p;
      return;
    }
    if (vis[r]) {
      cout << -1;
      return;
    }
    vis[r] = 1;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
