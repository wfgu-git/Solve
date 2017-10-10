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

char S[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  set<char> st = {begin(S), end(S)};
  int T;
  cin >> T;
  string raw;
  while (T--) {
    cin >> raw;
    int flag = 1;
    for (char ch : raw) {
      if (st.find(ch) == st.end()) {
        flag = 0;
        break;
      }
    }
    int n = raw.size();
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
      if (raw[i] != raw[j]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << "yes";
    } else {
      cout << "no";
    }
    cout << "\n";
  }
}
