#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("1003.in", "w", stdout);
  srand(time(0));
  int T = 100;
  for (int cas = 1; cas <= T; ++cas) {
    int n = rand() % 10 + 5;
    int m = rand() % 995 + 5;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
      int hp = rand() % 1001 + 1;
      int shield = rand() % 11;
      printf("%d %d\n", hp, shield);
    }
    for (int i = 0; i < m; ++i) {
      int k = rand() % 100001 + 10;
      int p = rand() % 1001 + 3;
      printf("%d %d\n", k, p);
    }
    printf("\n\n");
  }
}
