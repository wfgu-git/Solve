/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s, t;
  while (cin >> s >> t) {
    decltype(s.size()) sn = s.size();
    decltype(sn) tn = t.size();
    s = s + s;
    set<int> st;
    hash<string> h;
    for (decltype(sn) i = 0; i < sn; ++i) {
      st.insert(h(s.substr(i, tn)));
    }
    if (st.find(h(t)) != st.end()) {
      cout << "yes" << endl;
      continue;
    }
    cout << "no" << endl;
  }
  return 0;
}
