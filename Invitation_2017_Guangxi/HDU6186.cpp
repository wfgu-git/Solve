/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int a[maxn];
int bit[35], tmp[35];
int N, Q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> N >> Q) {
    memset(bit, 0, sizeof(bit));
    int raw_xor = 0;
    for (int x, i = 0; i < N; ++i) {
      cin >> x;
      a[i] = x;
      raw_xor ^= x;
      for (int j = 0; j < 33; ++j) {
        if ((x >> j) & 1) {
          ++bit[j];
        }
      }
    }
    int raw_and = 0, raw_or = 0;
    for (int i = 0; i < 33; ++i) {
      if (bit[i] == N) raw_and |= (1 << i);
      if (bit[i]) raw_or |= (1 << i);
    }

    for (int x, i = 0; i < Q; ++i) {
      int ans_xor, ans_and = 0, ans_or = 0;
      cin >> x;

      x = a[x - 1];
      ans_xor = raw_xor ^ x;

      memcpy(tmp, bit, sizeof(bit));
      for (int i = 0; i < 33; ++i) {
        tmp[i] = tmp[i] - ((x >> i) & 1);
        if (tmp[i] == N - 1) ans_and |= (1 << i);
      }

      memcpy(tmp, bit, sizeof(bit));
      for (int i = 0; i < 33; ++i) {
        if (tmp[i] - ((x >> i) & 1)) ans_or |= (1 << i);
      }
      cout << ans_and << " " << ans_or << " " << ans_xor << endl;
    }
  }
  return 0;
}
