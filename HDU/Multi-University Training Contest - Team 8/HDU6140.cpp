#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 20;
int N, K;
int a[maxn];
void work() {
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> a[i];
  }
  int max_sum = 0;
  int min_sum = 0;
  char t;
  for (int i = 1; i <= N; ++i) {
    cin >> t;
    if (t == 'L') {
      max_sum += a[i];
    } else if (t == 'D') {
      min_sum -= a[i];
    } else {
      max_sum += a[i];
      min_sum -= a[i];
    }
  }
  // printf("(%d, %d) K = %d\n", min_sum, max_sum, K);
  if (K <= max_sum && K >= min_sum) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
