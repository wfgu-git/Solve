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

  string s, u;
  stack<char> t;
  map<char, int> buc;
  cin >> s;
  for (char c : s) {
    buc[c]++;
  }
  for (char c : s) {
    if (c <= buc.begin()->first) {
      u.push_back(c);
      if (!--buc[c]) {
        buc.erase(c);
      }
    } else {
      while (t.size() && c > t.top() && t.top() <= buc.begin()->first) {
        u.push_back(t.top());
        t.pop();
      }
      if (!--buc[c]) {
        buc.erase(c);
      }
      if (c <= buc.begin()->first) {
        u.push_back(c);
      }
      t.push(c);
    }
  }
  while (!t.empty()) {
    u.push_back(t.top());
    t.pop();
  }
  cout << u;
}
