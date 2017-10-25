/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

int a[maxn];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  if (2 * k < n) {
    cout << 0;
    return 0;
  }
  int j = 0;
  for (int i = 0; i + k < n; ++i) {
    a[i + k] = ++j;
    a[i] = ++j;
  }
  for (int i = 0; i  < n; ++i) {
    if (!a[i]) {
      a[i] = ++j;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
}
