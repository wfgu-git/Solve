/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int mark[202];
int main() {
  int n;
  string raw;
  cin >> n >> raw;
  for (int i = 1; i < n; ++i) {
    if (raw[i] == raw[i - 1] && raw[i] >= 'a' && raw[i] <= 'z') {
      mark[i] = 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (mark[i]) {
      raw[i] = ' ';
    }
  }
  raw.erase(remove(raw.begin(), raw.end(), ' '), raw.end());
  for (int i = 0; i < n; ++i) {
    if (raw[i] >= 'A' && raw[i] <= 'Z') {
      raw[i] = ' ';
    }
  }
  stringstream ss;
  ss << raw;
  string str;
  int ans = 0;
  while (ss >> str) {
    set<char> ret = {str.begin(), str.end()};
    ans = max(ans, (int)ret.size());
  }
  cout << ans << endl;
}
