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
int val[maxn];
int ch[maxn][2];
bool not_root[maxn];
int n, root, ans;
map<int, int> ma;
map<int, int> S;
void dfs(int now, int l, int r) {
  if (l > r) return;
  if (val[now] >= l && val[now] <= r) {
    if (!S[val[now]]) {
      ans += ma[val[now]];
      S[val[now]] = true;
    }
  }
  if (ch[now][0] != -1) dfs(ch[now][0], l, min(val[now] - 1, r));
  if (ch[now][1] != -1) dfs(ch[now][1], max(l, val[now] + 1), r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i] >> ch[i][0] >> ch[i][1];
    ma[val[i]]++;
    if (ch[i][0] != -1) not_root[ch[i][0]] = true;
    if (ch[i][1] != -1) not_root[ch[i][1]] = true;
  }
  for (int i = 1; i <= n; ++i) {
    if (!not_root[i]) {
      root = i;
      break;
    }
  }
  dfs(root, 0, inf);
  cout << n - ans;
}
