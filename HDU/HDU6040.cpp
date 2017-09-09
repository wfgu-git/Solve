/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 10001000;
const int maxm = 100 + 20;

unsigned n, m, A, B, C, x, y, z;
unsigned w[maxn], tid[maxm], kth[maxm], ans[maxm];
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}
bool comp(int x, int y) {
  return kth[x] < kth[y];
}
void work(unsigned kase) {
  for (int i = 0; i < m; ++i) {
    scanf("%u", kth + i);
    tid[i] = i;
  }
  x = A; y = B; z = C;
  for (int i = 0; i < n; ++i) {
    w[i] = rng61();
  }
  sort(tid, tid + m, comp);
  tid[m] = m; kth[m] = n;
  for (int i = m - 1; i >= 0; --i) {
    if (kth[tid[i]] == kth[tid[i + 1]]) {
      ans[tid[i]] = ans[tid[i + 1]];
    } else {
      nth_element(w, w + kth[tid[i]], w + kth[tid[i + 1]]);
      ans[tid[i]] = w[kth[tid[i]]];
    }
  }
  printf("Case #%u:", kase);
  for (int i = 0; i < m; ++i) {
    printf(" %u", ans[i]);
  }
  printf("\n");
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  unsigned cas = 1;
  while (~scanf("%u%u%u%u%u", &n, &m, &A, &B, &C)) {
    work(cas++);
  }
  return 0;
}
