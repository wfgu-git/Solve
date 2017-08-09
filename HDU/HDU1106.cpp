#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;
  while (cin >> str) {
    for (char& ch : str) {
      if (ch == '5') {
        ch = ' ';
      }
    }
    stringstream ss(str);
    vector<int> ans;
    int x;
    while (ss >> x) {
      ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    int sz = ans.size();
    for (int i = 0; i < sz; ++i) {
      printf("%d%c", ans[i], (i == sz - 1 ? '\n' : ' '));
    }
  }
  return 0;
}
