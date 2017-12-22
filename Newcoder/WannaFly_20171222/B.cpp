/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

double a[15], b[15], c[15];
double p[15], np[15];
double ans[15];
void dfs(int pos, int now, double psb) {
  if (pos == 13) {
    ans[now] += psb;
    return;
  }
  dfs(pos + 1, now + 1, psb * p[pos]);
  dfs(pos + 1, now, psb * np[pos]);
}
void work() {
  for (int i = 1; i <= 12; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= 12; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= 12; ++i) {
    cin >> c[i];
  }

  for (int i = 1; i <= 12; ++i) {
    p[i] = 1.0 - (1.0 - a[i]) * (1.0 - b[i]) * (1.0 - c[i]);
    np[i] = 1.0 - p[i];
  }
  dfs(1, 0, 1);
  cout << setiosflags(ios::fixed);
  for (int i = 0; i <= 12; ++i) {
    cout << setprecision(6) << ans[i] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
