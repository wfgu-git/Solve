/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

ll Q[maxn];
int pos[maxn];
int main() {
  int M;
  ll D;
  while (scanf("%d%lld", &M, &D) != EOF) {
    char opt[2];
    ll x;
    ll t = 0L;
    int head = 1, tail = 0, p = 0;
    for (int i = 0; i < M; ++i) {
      scanf("%s%lld", opt, &x);
      if (opt[0] == 'A') {
        x = (x + t) % D;
        while (Q[tail] <= x && tail) {
          --tail;
        }
        Q[++tail] = x;
        pos[tail] = ++p;
      } else {
        int l = p - x + 1;
        int k = lower_bound(pos + head, pos + tail + 1, l) - pos;
        printf("%lld\n", Q[k]);
        t = Q[k];
      }
    }
  }
  return 0;
}
