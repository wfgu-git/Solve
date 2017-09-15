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
int lef[maxn], rig[maxn];
list<int>::iterator iter[maxn], p;
list<int> L;
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> n >> k;
    L.clear();
    p = L.begin();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      L.push_back(a[i]);
      iter[a[i]] = ++p;
    }

    ll ans = 0;
    int lcont, rcont;
    for (int i = 1; i <= n; ++i) {
      lcont = rcont = 1;
      int j;
      for (j = i + 1; j <= n; ++j) {
        if (rcont > k) {
          break;
        }
        if (a[j] > a[i]) {
          rig[rcont++] = j - i;
        }
      }
      if (j > n) {
        rig[rcont] = n - i;
      }
      for (j = i - 1; j >= 0; --j) {
        if (lcont > k) {
          break;
        }
        if (a[j] > a[i]) {
          lef[lcont++] = i - j;
        }
      }
      if (j <= 1) {
        lef[lcont] = i + 1;
      }
      for (j = 0; j < lcont; ++j) {
        if (k - j - 1 >= rcont) {
          continue;
        }
        ans += 1L * a[i] * (ll)(lef[j + 1] - lef[j]) * (ll)(rig[k - j] * rig[k - j - 1]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
