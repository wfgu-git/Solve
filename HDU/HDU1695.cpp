/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int euler(int n) {
  if (n == 1) {
    return 1;
  }
  int i  = 2, m = n, root = (int)sqrt(n);
  while (i <= root) {
    if (m % i == 0) {
      n -= n / i;
      while (m % i == 0) {
        m /= i;
      }
      root = (int)sqrt(m);
    }
    ++i;
  }
  if (m != 1) {
    n -= n / m;
  }
  return n;
}
int Q[100000];
int top;
void work() {
  int T, kase = 0;
  scanf("%d", &T);
  while (T--) {
    int a, b, c, d, k;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    if (!k ) {
      printf("Case %d: 0\n", ++kase);
      continue;
    }

    if (b > d) swap(b, d);
    b /= k;
    d /= k;
    ll ans = 0;
    for (int i = 1; i <= b; ++i) {
      ans += euler(i);
    }
    for (int i = b + 1; i <= d; ++i) {
      int x = i;
      vector<int> vi;
      for (int j = 2; j * j <= x; ++j) {
        if (x % j == 0) {
          vi.push_back(j);
          do {
            x /= j;
          } while (x % j == 0);
        }
      }
      if (x > 1) vi.push_back(x);
      int tot = vi.size();

      top = 0;
      Q[top++] = -1;
      for (int p = 0; p < tot; ++p) {
        int k = top;
        for (int q = 0; q < k; ++q) {
          Q[top++] = Q[q] * vi[p] * (-1);
        }
      }
      ll tmp = 0;
      for (int j = 1; j < top; ++j) {
        tmp += b / Q[j];
      }
      ans += b - tmp;
    }
    printf("Case %d: %lld\n", ++kase, ans);
  }
}
int main() {
  // freopen("data.in", "r", stdin);

  work();
}
