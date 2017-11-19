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
const int maxn = 1000000 + 20;

int n;
int d[maxn];
void work() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int L;
    cin >> L;
    int idx = max(1, i - L);
    d[idx]++;
    d[i]--;
  }
  for (int i = 1; i <= n; ++i) {
    d[i] += d[i - 1];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == 0) ++ans;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
