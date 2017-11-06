/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 20;

int n;
int a[maxn];
int dfs(int L, int R, int S) {
  if (L > R) {
    return 0;
  }

  int Min = inf;
  int pos, sum = 0;
  for (int i = L; i <= R; ++i) {
    if (a[i] < Min) {
      Min = a[i];
      pos = i;
    }
    if (a[i] > S) {
      sum++;
    }
  }
  int temp = Min - S;
  return min(sum, dfs(L, pos - 1, a[pos]) + dfs(pos + 1, R, a[pos]) + temp);
}

void work() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = min(n, dfs(1, n, 0));
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
