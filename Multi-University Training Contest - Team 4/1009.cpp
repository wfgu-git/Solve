#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    scanf("%d", &n);
    int cnt_even = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      if (x % 2 == 0) {
        ++cnt_even;
      }
    }
    if (cnt_even > n / 2) {
      printf("2 0\n");
    } else {
      printf("2 1\n");
    }
  }
  return 0;
}
