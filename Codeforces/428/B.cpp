#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 20;
int a[maxn];
int n, k;
inline void work() {
  for (int i = 0; i < k; ++i) {
    scanf("%d", a + i);
  }
  int one = 0;
  int two = n * 2;
  int four = n;
  for (int i = 0; i < k; ++i) {
    if (a[i] >= 4) {
      if (four) {
        if (four - a[i] / 4 >= 0) {
          four -= a[i] / 4;
          a[i] %= 4;
        } else {
          a[i] -= 4 * four;
          four = 0;
        }
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    if (a[i] >= 2) {
      if (two) {
        if (two - a[i] / 2 >= 0) {
          two -= a[i] / 2;
          a[i] %= 2;
        } else {
          a[i] -= 2 * two;
          two = 0;
        }
      }
    }
  }

  if (four > 0) two += four; one += four;

  for (int i = 0; i < k; ++i) {
    if (a[i] >= 2) {
      if (two - a[i] / 2 >= 0) {
        two -= a[i] / 2;
        a[i] %= 2;
      }
    }
  }

  one += two;

  int cont = 0;
  for (int i = 0; i < k; ++i) {
    cont += a[i];
  }
  if (cont > one) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    work();
  }
}
