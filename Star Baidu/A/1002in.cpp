#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("1002.in", "w", stdout);
  srand(time(0));
  int L = rand() % 100000 + 200;
  printf("%d\n", L);
  for (int i = 0; i < L; ++i) {
    int u = rand() % 100000 + 1;
    int v = rand() % 100000 + 1;
    int k = rand() % 2;
    printf("%d %d %d\n", u, v, k);
  }
  return 0;
}
