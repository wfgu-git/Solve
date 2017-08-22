/*
东东是最强的
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
    return ((ch == rhs.ch || rhs.ch == '.') && (lb >= rhs.lb)) || (rhs.ch == '?');
  }
} ;
vector<Mystring> s, t;
bool dfs(int curs, int curt) {
  if (curs == s.size()) {
    for (int i = curt; i < t.size(); ++i) {
      if (t[i].lb != 0) {
        return 0;
      }
    }
    return 1;
  }
  for (int i = curt; i < t.size(); ++i) {
    if (s[curs] == t[i]) {
      if (t[i].ch == '.' || t[i].ch == '?') {
        if (s[curs].lb >= t[i].lb) {
          int tmp = s[curs].lb;
          s[curs].lb -= (t[i].ch == '?' ? tmp : t[i].lb);
          if (dfs(curs, i + 1)) return 1;
          s[curs].lb += (t[i].ch == '?' ? tmp : t[i].lb);
        } else if (s[curs].lb < t[i].lb) {
          t[i].lb -= (t[i].ch == '.' ? s[curs].lb : 1);
          if (dfs(curs + 1, i)) return 1;
          t[i].lb += (t[i].ch == '.' ? s[curs].lb : 1);
        }
      } else {
        s[curs].lb -= t[i].lb;
        if (dfs(curs + 1, i + 1)) return 1;
        s[curs].lb += t[i].lb;
      }
    } else if (t[i].lb) return 0;
  }
  return 0;
}
void work() {
  s.clear(); t.clear();
  string oris, orit;
  cin >> oris >> orit;
  int slen = oris.size();
  int tlen = orit.size();
  string tmp;
  for (int i = 0; i < tlen; ++i) {
    if (orit[i] == '.' && i + 1 < tlen && orit[i + 1] == '*') {
      tmp.push_back('?');
    } else {
      tmp.push_back(orit[i]);
    }
  }
  orit = tmp;
  tlen = orit.size();
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

  if (dfs(0, 0)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
