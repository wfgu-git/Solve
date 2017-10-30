/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int N, M, Q;
ll d[maxn];
ll cum[maxn];
map<int, ll> dp[maxn];
ll get_dist(int x, int y) {
  if (x == y) return 0;
  if (x > y) swap(x, y);
  ll d1 = cum[y] - cum[x];
  ll d2 = cum[x] - cum[n] - cum[y] + d[1];
  return min(d1, d2);
}
void work() {
  cin >> N >> M;
  cum[1] = 0;
  for (int i = 2; i <= N; ++i) {
    cin >> d[i];
    cum[i] = cum[i - 1] + d[i];
  }
  d[1] = d[N];

  for (int i = 0; i < M; ++i) {
    cin >> u[i] >> v[i] >> t[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
