/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll Q[1 << 21];
int top;
vector<ll> vi;
void work() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    --n;
    vi.clear();
    for (int i = 0; i < m; ++i) {
      int x;
      scanf("%d", &x);
      if (x != 0) vi.push_back(x);
    }
    m = vi.size();

    top = 0;
    Q[top++] = -1;
    for (int i = 0; i < m; ++i) {
      int k = top;
      for (int j = 0; j < k; ++j) {
        Q[top] = Q[j] * vi[i] * (-1);
        Q[top] /= __gcd(abs(Q[j]), abs(vi[i]));
        top++;
      }
    }

    ll ans = 0;
    for (int i = 1; i < top; ++i) {
      ans += n / Q[i];
    }
    printf("%lld\n", ans);
  }
}
int main() {
  // freopen("data.in", "r", stdin);

  work();
}
