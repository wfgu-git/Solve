/*
   教练我要打ACM!
   Life has never been fucking so easy...
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a[10];
  int sp[4] = {0, 5, 3, 1};
  while (true) {
    for (int i = 1; i <= 6; ++i) {
      cin >> a[i];
    }
    if (*max_element(a + 1, a + 7) == 0) break;
    int sum = a[6] + a[5] + a[4] + ceil(1.0 * a[3] / 4.0);
    int x2 = 5 * a[4] + sp[a[3] % 4];
    if (a[2] > x2) {
      sum += ceil((a[2] - x2)/ 9.0);
    }
    int x1 = 36 * sum - 36 * a[6] - 25 * a[5] - 16 * a[4] - 9 * a[3] - 4 * a[2];
    if (a[1] > x1) {
      sum += ceil((a[1] - x1)/ 36.0);
    }
    cout << sum << endl;
  }
  return 0;
}
