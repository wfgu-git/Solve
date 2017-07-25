#include <bits/stdc++.h>
using namespace std;
int main() {
  set<char> good, bad;
  for (char c = 'a'; c <= 'z'; ++c) bad.insert(c);
  string pat, ob, goods, str;
  int q;
  cin >> goods >> str >> q;
  for (char ch : goods) {
    good.insert(ch);
    bad.erase(ch);
  }
  bool has = false;
  if (str.find('*') < str.size()) has = true;
  for (int k = 0; k < q; k++) {
    ob = str;
    cin >> pat;
    int plen = pat.size();
    int slen = ob.size();
    bool flag = true;
    if (!has) {
      if (plen != slen) {
        cout << "NO" << endl;
        continue;
      } else {
        for (int i = 0; i < plen; i++) if (ob[i] != pat[i]) {
            if (ob[i] == '?' && good.find(pat[i]) != good.end()) continue;
            else {flag = false; break;}
        }
      }
    } else {
      if (plen + 1 < slen) {
        cout << "NO" << endl;
        continue;
      } else if (plen + 1 == slen) {
        ob.erase(ob.find('*'), 1);
      } else if (plen > slen) {
        string temp = "";
        for (int l = 0; l < plen - slen; l++) temp.push_back('*');
        ob.insert(ob.find('*'), temp);
      }
      for (int i = 0; i < plen; i++) if (ob[i] != pat[i]) {
        if (ob[i] == '?' && good.find(pat[i]) != good.end()) continue;
        else if (ob[i] == '*' && bad.find(pat[i]) != bad.end()) continue;
        else {flag = false; break;}
      }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
