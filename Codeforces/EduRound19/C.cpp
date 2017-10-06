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

char mn[maxn];
int main() {
  string s;
  stack<char> t;
  cin >> s;
  int n = s.size();
  mn[n] = 127;
  for (int i = n - 1; i >= 0; --i) {
    mn[i] = min(mn[i + 1], s[i]);
  }
  int p = 0;
  while (!t.empty() || p < n) {
    if (!t.empty() && t.top() <= mn[p]) {
      cout << t.top();
      t.pop();
    } else {
      t.push(s[p]);
      ++p;
    }
  }
}
