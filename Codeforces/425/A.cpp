#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  while (cin >> n >> k) {
    int t = n / k;
    if (t % 2 == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
