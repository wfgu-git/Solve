#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int sl, tl;
vector < int > check(const string &s, const string &t) {
  vector < int > ret;
  for (int i = 0; i < sl; i++) {
    if (s[i] != t[i]) {
        ret.push_back(i + 1);
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> sl >> tl;
  string s, t;
  cin >> s >> t;
  vector < int > ans;
  int cnt = inf;
  for (int i = 0; i + sl - 1 < tl; i++) {
    string tt = t.substr(i, sl);
    vector < int > temp = check(s, tt);
    if (temp.size() < cnt) {
        cnt = temp.size();
        ans = temp;
    }
  }
  cout << cnt << endl;
  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}
