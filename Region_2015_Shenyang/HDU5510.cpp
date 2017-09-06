/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 20;

int fail[maxn];
void get_fail(const string& t) {
  fail[0] = -1;
  int n = t.size();
  int j = 0;
  int k = -1;
  while (j < n) {
    if (k == -1 || t[j] == t[k]) {
      fail[++j] = ++k;
    } else {
      k = fail[k];
    }
  }
}
int KMP(const string& s, const string& t) {
  get_fail(t);
  int sn = s.size();
  int tn = t.size();
  int i = 0;
  int j = 0;
  while (i < sn && j < tn) {
    if (j == -1 || s[i] == t[j]) {
      ++i; ++j;
    } else {
      j = fail[j];
    }
  }
  if (j == tn) return i - tn + 1;
  else return -1;
}
bool vis[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  vector<string> belly;
  for (int cas = 1; cas <= T; ++cas) {
    belly.clear();
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; ++i) {
      cin >> str;
      belly.push_back(str);
    }
    memset(vis, 0, sizeof(vis));
    int ret = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (vis[j]) continue;
        if (KMP(belly[i], belly[j]) == -1) {
          ret = i + 1;
          break;
        } else {
          vis[j] = true;
        }
      }
    }
    cout << "Case #" << cas << ": " << ret << endl;
  }
  return 0;
}
