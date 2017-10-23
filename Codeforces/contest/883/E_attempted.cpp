/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  string raw;
  cin >> raw;
  int m;
  cin >> m;
  vector<string> strs;
  string tmp;
  for (int i = 0; i < m; ++i) {
    cin >> tmp;
    strs.push_back(tmp);
  }
  int not_know = 0;
  set<char> know;
  for (char & ch : raw) {
    if (ch == '*') net_know++;
    else know.insert(ch);
  }
  
}
