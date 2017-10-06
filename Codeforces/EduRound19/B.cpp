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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int sum = 0;
  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > 0) a.push_back(x);
    if (x < 0) b.push_back(x);
  }
  for (int x : a) {
    sum += x;
  }
  if (sum & 1) {
    return cout << sum, 0;
  }
  int mn = inf;
  for (int x : a) {
    if (x & 1) mn = min(mn, x);
  }
  int mx = -inf;
  for (int x : b) {
    if (x & 1) mx = max(mx, x);
  }
  if (mn == inf && mx != -inf)  sum += mx;
  else if (mn != inf && mx == -inf)  sum -= mn;
  else sum = max(sum + mx, sum - mn);
  cout << sum;
}
