/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const int moder = 1e9 + 7;

int dp[maxn];
char str[maxn];
map<string, int> S;
int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  S["NW"] = 1;
  S["SW"] = 1;
  S["NE"] = 1;
  S["SE"] = 1;
  while (~scanf("%s", str + 1)) {
    int n = strlen(str + 1);

    dp[0] = 1;
    dp[1] = 1;
    string tmp;
    for (int i = 2; i <= n; ++i) {
      tmp.clear();
      tmp.push_back(str[i - 1]);
      tmp.push_back(str[i]);
      if (S.count(tmp)) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= moder;
      } else {
        dp[i] = dp[i - 1];
      }
    }
    printf("%d\n", dp[n] % moder);
  }
}
