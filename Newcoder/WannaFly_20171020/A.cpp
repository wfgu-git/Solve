/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

vector<pair<int, int> > raw, st;
set<int, greater<int> > Y;
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    st.push_back({x, y});
    Y.insert(y);
  }
  int ans = 0;
  sort(st.begin(), st.end());
  for (int i = 0; i < n - 1; ++i) {
    Y.erase(st[i].second);
    int Max = *Y.begin();
    if (Max > st[i].second) ans++;
  }
  cout << ans;
}
