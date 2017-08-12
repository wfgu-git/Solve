#include<bits/stdc++.h>
using namespace std;
inline bool check(int y) {return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));}
inline void work() {
  int y, m, d;
  scanf("%d-%d-%d", &y, &m, &d);
  int k = 0;
  if (m > 2) {
    while (true) {
      ++y;
      if (check(y)) k += 2;
      else ++k;
      k %= 7;
      if (!k) break;
    }
  } else if (m == 1 || (m == 2 && d <= 28)) {
    while (true) {
      ++y;
      if (check(y - 1)) k += 2;
      else ++k;
      k %= 7;
      if (!k) break;
    }
  } else if (m == 2 && d == 29) {
    while (true) {
      ++y;
      if (check(y - 1)) k += 2;
      else ++k;
      k %= 7;
      if (!k && check(y)) break;
    }
  }
  printf("%d\n", y);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
