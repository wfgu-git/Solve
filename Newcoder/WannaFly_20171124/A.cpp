/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

int n, x;
ll a[maxn];
int vis[maxn];
void work() {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    vis[a[i] + 2000] = 1;
  }
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ll c = a[i] * x * x + a[j] * x;
      c = -c;
      c += 2000;
      if (c < 0 || c > 5000) continue;
      if (vis[c]) flag = 1;
    }
  }
  if (flag) cout << "YES";
  else cout << "NO";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
