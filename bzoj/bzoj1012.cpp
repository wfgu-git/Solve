/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

ll Q[maxn], a[maxn];
int main() {
  int M, D;
  while (scanf("%d%d", &M, &D) != EOF) {
    char opt[2];
    ll x, t = 0;
    int len = 0;
    scanf("%s%lld", opt, &x);
    if (opt[0] == 'A') {
      a[++len] = (t + x) % D;
      for (int i = len; i >= 1; --i) {
        if (Q[i] < a[len]) {
          Q[i] = a[len];
        } else {
          break;
        }
      }
    } else {
      printf("%lld\n", Q[len - x + 1]);
      t = Q[len - x + 1];
    }
  }
  return 0;
}
