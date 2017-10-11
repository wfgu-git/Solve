/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

int n, V;
int w[maxn], c[maxn];
int dp[maxn];
string choose[maxn];
int main() {
  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int kase = 0;
  while (cin >> n >> V) {
    if (kase) cout << endl;
    for (int i = 0; i <= V; ++i) {
      choose[i].clear();
      for (int j = 0; j < n; ++j) {
        choose[i].push_back('0');
      }
    }
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      for (int v = V; v >= 0; --v) if (v >= c[i]) {
        if (dp[v - c[i]] + w[i] == dp[v]) {
          string tmp = choose[v - c[i]];
          tmp[i] = '1';
          if (tmp < choose[v]) {
            choose[v] = tmp;
          }
        }
        if (dp[v - c[i]] + w[i] > dp[v]) {
          dp[v] = dp[v - c[i]] + w[i];
          choose[v] = choose[v - c[i]];
          choose[v][i] = '1';
        }
      }
    }
    cout << "Case " << ++kase << '\n' << dp[V] << " ";
    cout << choose[V];
  }
}
