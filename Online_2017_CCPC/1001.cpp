#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<int, int> > G;
int main() {
  // freopen("data.out", "w", stdout);
  N = 80;
  int now = 80;
  for (int i = 1; i <= N; ++i) {
    int d = N / i;
    for (int j = 0; j < d; j++) {
      ++now;
      for (int k = 1; k <= i; ++k) {
        G.push_back({now, i * j + k});
      }
    }
  }
  M = G.size();
  printf("%d %d\n", now, M);
  for (pair<int, int>& p : G) {
    printf("%d %d\n", p.first, p.second);
  }
  printf("80\n");
  for (int i = 1; i <= 80; ++i) {
    printf("%d\n", i);
  }
  return 0;
}
