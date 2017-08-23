/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

int n, q;
map<int, ll> key, sum;
ll get_sum(int x) {
  if (x > n) return 0;
  if (sum.count(x)) return sum[x];

  int ldep, rdep;
  ldep = rdep = 0;
  int tmp = x;
  while ((tmp << 1) <= n) {
    ++ldep; tmp = tmp << 1;
  }
  tmp = x;
  while ((tmp << 1 | 1) <= n) {
    ++rdep; tmp = tmp << 1 | 1;
  }
  if (ldep != rdep) tmp = n;

  ll ret = 0;
  while (tmp >= x) {
    ret += tmp; tmp /= 2;
  }
  return ret;
}
void update(int x, ll y) {
  key[x] = y;
  sum[x] = max(get_sum(x << 1), get_sum(x << 1 | 1)) + (key.count(x) ? key[x] : x);
  while (x >> 1) {
    x /= 2;
    sum[x] = max(get_sum(x << 1), get_sum(x << 1 | 1)) + (key.count(x) ? key[x] : x);
  }
}
ll query(int x) {
  ll ret = get_sum(x << 1) + get_sum(x << 1 | 1) + (key.count(x) ? key[x] : x);
  ll tmp = get_sum(x);
  ll up = 0;
  while (x >> 1) {
    up += (key.count(x >> 1) ? key[x >> 1] : (x >> 1));
    if (x & 1) {
      ret = max(ret, tmp + up + get_sum(x ^ 1));
    } else {
      ret = max(ret, tmp + up + get_sum(x ^ 1));
    }
    x >>= 1;
  }
  return ret;
}
void work() {
  key.clear(); sum.clear();
  char op[10];
  for (int i = 0; i < q; ++i) {
    scanf("%s", op);
    int x;
    ll y;
    if (op[0] == 'q') {
      scanf("%d", &x);
      printf("%lld\n", query(x));
    } else {
      scanf("%d%lld\n", &x, &y);
      update(x, y);
    }
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &n, &q) != EOF) {
    work();
  }
  return 0;
}
