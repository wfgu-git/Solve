/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int gethash(const std::string &str) {
  ll res = 0;
  for (char c : str) res = (res * 131 + c) % 1000000007;
  return res;
}
string str[2][maxn];
// gp_hash_table<int, int> mep[2];
cc_hash_table<int, int> mep[2];
void solve(const string& s, int t) {
  int val = gethash(s);
  auto it = mep[t].find(val);
  if (it == mep[t].end()) {
    cout << "what?" << endl;
  } else {
    cout << str[t ^ 1][mep[t][val]] << endl;
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  string raw;
  int tot = 0;
  while (getline(cin, raw)) {
    if (raw == "@END@") {
      break;
    }
    int p = raw.find(']');
    str[0][tot] = raw.substr(1, p - 1);
    str[1][tot] = raw.substr(p + 2);
    mep[0][gethash(str[0][tot])] = tot;
    mep[1][gethash(str[1][tot])] = tot;
    tot++;
  }
  int Q;
  cin >> Q;
  cin.get();
  string s;
  while (Q--) {
    getline(cin, raw);
    if (raw[0] == '[') {
      s = raw.substr(1, raw.size() - 2);
      solve(s, 0);
    } else {
      solve(raw, 1);
    }
  }
}
