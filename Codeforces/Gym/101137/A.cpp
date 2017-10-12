/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int a[maxn * 2 + 5];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[i] = a[i + n] = x;
    }
    int i, j, k;
    j = max_element(a, a + 2 * n) - a;
    i = j - 1;
    k = j + 1;
    if (j == 0) {
      i = n - 1;
      k = j + 1;
    }
    if (j == n - 1) {
      i = j - 1;
      k = 0;
    }
    cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
  }
}
