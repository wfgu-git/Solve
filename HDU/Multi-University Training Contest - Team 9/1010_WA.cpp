/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
struct Mystring {
  char ch;
  int lb, ub;
  bool operator == (const Mystring& rhs) const {
    return (ch == rhs.ch || rhs.ch == '.') && (rhs.lb <= lb && ub <= rhs.ub);
  }
} ;
vector<Mystring> s, t;
void work() {
  s.clear(); t.clear();
  string oris, orit;
  cin >> oris >> orit;
  int slen = oris.size();
  int tlen = orit.size();
  int p = 0, num = 0;
  char now = '#', last = '#';
  while (p < slen) {
    now = oris[p];
    if (now != last) {
      if (last != '#') {
        s.push_back({last, num, num});
      }
      last = now;
      num = 1;
    } else {
      num++;
    }
    ++p;
  }
  s.push_back({last, num, num});

  p = 0; num = 0;
  now = '#'; last = '#';
  bool flag = 0;
  while (p < tlen) {
    now = orit[p];
    if (now != last) {
      if (last != '#') {
        t.push_back({last, num, flag ? inf : num});
      }
      last = now;
      num = 0;
      flag = 0;
      p--;
    } else {
      if (p + 1 < tlen && orit[p + 1] == '*') {
        flag = 1;
        ++p;
      } else {
        num++;
      }
    }
    ++p;
  }
  t.push_back({last, num, flag ? inf : num});

  int cur = 0;
  for (Mystring& x : s) {
    for (int i = 0;; ++i) {
      if (i >= t.size()) {
        cout << "no" << endl;
        return;
      }
      if (x == t[i]) {
        cur = i + 1;
        break;
      }
    }
  }
  cout << "yes" << endl;
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
