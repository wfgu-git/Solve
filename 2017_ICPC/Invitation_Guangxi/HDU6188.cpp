/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 20;

int cont[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int n;
  while (scanf("%d", &n) == 1) {
    memset(cont, 0, sizeof(cont));
    for (int tmp, i = 0; i < n; ++i) {
      scanf("%d", &tmp);
      ++cont[tmp];
    }
    int tot = 0;
    for (int i = 1; i < maxn - 1; ++i) {
      if (cont[i] / 2 > 0) {
        tot += cont[i] / 2;
        cont[i] %= 2;
      }
      if (cont[i]) {
        if (cont[i + 1] & 1 && cont[i + 2]) {
          ++tot;
          --cont[i + 1]; --cont[i + 2];
        }
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
