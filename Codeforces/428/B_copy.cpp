#include <iostream>
using namespace std;
int i, n, k, a, s, j;
int main() {
  for (cin >> n >> k; i < k; i++) cin >> a, a % 2 ? a++, j++ : 0, s += a;
  cout << (s > 8 * n || s == 8 * n && k == 4 * n && j < n ? "NO" : "YES");
}
