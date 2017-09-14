/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

const ull base = 1000009;
ull hss[maxn];
ull hst[maxn];
ull p[maxn];
void init(char s[], int n, ull hs[]) {
  hs[0] = 0;
  for (int i = 0; i < n; ++i) {
    hs[i + 1] = hs[i] * base + s[i];
  }
}
// get [l, r] ==> get(l + 1, r + 1);
ull get(ull hs[], int l, int r) {
  return hs[r] - hs[l - 1] * p[r - l + 1];
}
char s[maxn], t[maxn];
int n, m;
ull a[maxn];
bool check(int len) {
  int cont = 0;
  for (int i = 0; i + len - 1 < n; ++i) {
    a[cont++] = get(hss, i + 1, i + len - 1 + 1);
  }

  sort(a, a + cont);
  for (int i = 0; i + len - 1 < m; ++i) {
    ull t = get(hst, i + 1, i + len - 1 + 1);
    if (binary_search(a, a + cont, t)) {
      return true;
    }
  }
  return false;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  p[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    p[i] = p[i - 1] * base;
  }
  while (scanf("%s%s", s, t) != EOF) {
    n = strlen(s);
    m = strlen(t);
    init(s, n, hss);
    init(t, m, hst);

    int lb = 0, ub = min(n,  m);
    int ans = 0;
    while (lb <= ub) {
     int mid = (lb + ub) / 2;
     if (check(mid)) {
       lb = mid + 1;
       ans = mid;
     } else {
       ub = mid - 1;
     }
    }
    printf("%d\n", ans);
  }
}
