/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

int prexor[maxn];
int a[maxn];
int bucket[3000];
void work() {
  int T;
  cin >> T;
  while (T--) {
    memset(bucket, -1, sizeof(bucket));
    int n;
    cin >> n;
    prexor[0] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      prexor[i] = prexor[i - 1] ^ a[i];
      for (int j = 1; j <= i; ++j) {
        int t = prexor[j - 1] ^ prexor[i];
        bucket[t] = max(bucket[t], i - j + 1);
      }
    }
    int m;
    cin >> m;
    while (m--) {
      int x;
      cin >> x;
      int ans = 0;
      int dist = -1;
      for (int i = max(x, 0); i < 2048; ++i) {
        if (bucket[i] != -1) {
          ans = bucket[i];
          dist = abs(x - i);
          break;
        }
      }
      for (int i = max(x, 0); i >= 0; --i) {
        if (bucket[i] != -1) {
          int d = abs(x - i);
          if (d < dist || ans == 0) ans = bucket[i];
          if (dist != -1 && d == dist) {
            ans = max(ans, bucket[i]);
          }
          break;
        }
      }
      cout << ans << '\n';
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
