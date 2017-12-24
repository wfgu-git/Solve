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
  int n;
  cin >> n;
  int prev = 0;
  for (int i = 0; i < n; ++i) {
    int s, d;
    cin >> s >> d;
    int j;
    for (j = 0; ; ++j) {
      if (s + j * d > prev) {
        break;
      }
    }
    prev = s + j * d;
  }
  cout << prev;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
