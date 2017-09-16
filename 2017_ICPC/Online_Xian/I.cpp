/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

vector<string> st;
string raw, a, b, c, d;
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T, Q;
  cin >> T;
  while (T--) {
    st.clear();
    cin >> Q;
    int opt;
    for (int i = 0; i < Q; ++i) {
      cin >> opt;
      if (opt == 1) {
        cin >> raw;
        st.push_back(raw);
      } else {
        int ans = 0;
        cin >> a >> b >> c >> d;
        int sa = a.size();
        int sb = b.size();
        int sc = c.size();
        int sd = d.size();
        for (const string& str : st) {
          string qs = a;
          int n = str.size() / 2;
          int s1n = n - sa - sb;
          if (s1n < 0) continue;
          qs.push_back('.');
          qs.push_back('{');
          qs.append(to_string(s1n));
          qs.push_back('}');
          qs.append(b);
          qs.append(c);
          int s2n = n - sc - sd;
          qs.push_back('.');
          qs.push_back('{');
          qs.append(to_string(s2n));
          qs.push_back('}');
          qs.append(d);

          regex expr(qs);
          ans += (int)regex_match(str, expr);
        }
        cout << ans << endl;
      }
    }

  }
  return 0;
}
