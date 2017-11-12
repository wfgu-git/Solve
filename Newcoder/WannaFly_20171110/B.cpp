/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

int a[1005];
void work() {
  int n, m, k;
  while (cin >> n >> m >> k) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int maxv = *max_element(a, a + n);
    int minv = *min_element(a, a + n);
    cout << ceil(k * 3.6 / (maxv + m)) << ' ' << ceil(k * 3.6 / (minv + m));
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  // freopen("data.in", "r", stdin);
  work();
}
