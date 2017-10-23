/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

void del(string & str) {
  str.erase(remove(str.begin(), str.end(), '.'), str.end());
}
void init(string & str) {
  string tmp;
  int n = str.size();
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'u') {
      tmp += "oo";
    } else {
      tmp.push_back(str[i]);
    }
  }
  str = tmp;
  int flag = 0;
  while (true) {
    int n = str.size();
    for (int i = 1; i < n; ++i) {
      if (str[i] == 'h' && str[i - 1] == 'k') {
        str[i - 1] = '.';
        flag = 1;
      }
    }
    del(str);
    if (!flag) break;
    flag = 0;
  }
  n = str.size();
}
int main() {
  int n;
  cin >> n;
  string raw;
  map<string, int> cont;
  for (int i = 0; i < n; ++i) {
    cin >> raw;
    init(raw);
    cont[raw]++;
  }
  cout << cont.size();
  return 0;
}
