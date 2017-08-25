/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

void work() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    int num = n * m - 1;
    int cont = 0;
    while (num > p) {
      n = (num - 1) / p + 1;
      cont += n * (n - 1) / 2 * (p - 1);
      num -= n;
    }
    if (cont & 1) printf("%s\n", "NO");
    else printf("%s\n", "YES");
  }
}
int main() {
  work();
  return 0;
}
