/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int T;
string raw;
stringstream ss;
char S[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
int Mp[2000 * 2 + 1];
char Ma[2000 * 2 + 1];
int Manacher(const string& str) {
  int l = 0, len = str.size();
  Ma[l++] = '$';
  Ma[l++] = '#';
  for (int i = 0; i < len; ++i) {
    Ma[l++] = str[i];
    Ma[l++] = '#';
  }
  Ma[l] = 0;
  int mx = 0, id = 0;
  for (int i = 0; i < l; ++i) {
    Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
    while (Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
    if (i + Mp[i] > mx) {
      mx = i + Mp[i];
      id = i;
    }
  }
  int ret = 0;
  for (int i = 0; i < 2 * len + 2; ++i) {
    ret = max(ret, Mp[i] - 1);
  }
  return ret;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/solve/data.out", "w", stdout);

  set<char> st = {begin(S), end(S)};
  int T;
  cin >> T;
  while (T--) {
    cin >> raw;
    for (char & ch : raw) {
      if (st.find(ch) == st.end()) {
        ch = ' ';
      }
    }
    ss.clear();
    ss << raw;
    string tmp;
    int ans=  0;
    while (ss >> tmp) {
      ans = max(ans, Manacher(tmp));
    }
    cout << ans << '\n';
  }
}
