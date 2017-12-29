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

int a[maxn];
void work() {
  for (int i = 0; i < 3; ++i) {
    int x;
    cin >> x;
    a[x]++;
  }
  if (a[1] || a[2] >= 2 || a[3] == 3 ||
    (a[2] == 1 && a[4] == 2)) {
    cout << "YES";
  } else {
    cout << "NO";
  }

}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
