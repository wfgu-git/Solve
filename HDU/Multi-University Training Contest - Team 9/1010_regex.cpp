/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

void work() {
  string s, t, tmp;
  cin >> s >> t;
  int tlen = t.size();
  int cont = 0;
  for (int i = 0; i < tlen; ++i) {
    if (i + 1 < tlen && t[i] == '.' && t[i + 1] == '*') {
      cont++;
      tmp.push_back('(');
      tmp.push_back(t[i]);
      tmp.push_back(')');
      tmp.push_back('\\');
      tmp.push_back('0' + cont);
      tmp.push_back('*');
      ++i;
    } else {
      tmp.push_back(t[i]);
    }
  }
  t = tmp;
  regex expr(t);
  bool ret = regex_match(s, expr);
  if (ret) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
