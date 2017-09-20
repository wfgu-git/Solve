/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

int T;
int n, k;
int a[maxn];
int pre[maxn], nxt[maxn], pos[maxn];
int rig[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      pos[a[i]] = i;
      pre[i] = i - 1;
      nxt[i] = i + 1;
    }
    pre[0] = 0;
    nxt[n + 1] = n + 1;

    ll ans = 0;
    for (int v = 1; v <= n; ++v) {
      int x = pos[v];
      int lcont = 0, rcont = 0;
      for (int i = x; i <= n && rcont < k; i = nxt[i]) {
        rig[++rcont] = nxt[i] - i;
      }
      ll tmp = 0;
      for (int i = x; i > 0 && lcont < k; i = pre[i]) {
        lcont++;
        int r = k - lcont + 1;
        if (r > rcont) {
          continue;
        }
        tmp += (i - pre[i]) * rig[r];
      }
      ans += tmp * v;
      pre[nxt[x]] = pre[x];
      nxt[pre[x]] = nxt[x];
    }
    cout << ans << endl;
  }
  return 0;
}
