/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;


int w[maxn];
int c[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int n, W, V;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> n >> W >> V;
    int sumw = 0;
    int sumc = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> w[i];
      sumw += w[i];
    }
    for (int i = 1; i <= n; ++i) {
      cin >> c[i];
      sumc += c[i];
    }
    if (W >= sumw && V >= sumc) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}
