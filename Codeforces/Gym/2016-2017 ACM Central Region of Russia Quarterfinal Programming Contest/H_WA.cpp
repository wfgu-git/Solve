/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n;
ull dp[105];
ull dfs(int pos, bool lead) {
  if (!lead && dp[pos]) return dp[pos];
  if (pos == 0) {
    return 1;
  }
  ull ans = 0;
  for (int i = 0; i <= 9; ++i) {
    if (lead && !i) continue;
    if (n - pos + 1 == i) continue;
    ans += dfs(pos - 1, lead && i == 0);
  }
  if (!lead) dp[pos] = ans;
  return ans;
}
long long ret[101];
int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n) {
    memset(dp, 0, sizeof(dp));
    cout << dfs(n, 1) << endl;
  }
}
