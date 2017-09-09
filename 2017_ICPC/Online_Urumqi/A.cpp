/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

map<int, vector<int> > like, from;
map<int, set<int> > ans;
set<int> st;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int N, M;
    cin >> N >> M;
    st.clear();
    ans.clear();
    like.clear();
    from.clear();
    int u, v;
    for (int i = 0; i < N; ++i) {
      cin >> u >> v;
      like[u].push_back(v);
      st.insert(u);
    }
    for (int i = 0; i < M; ++i) {
      cin >> u >> v;
      from[u].push_back(v);
    }
    for (const int& x : st) {
      const vector<int>& vi = like[x];
      for (const int& y : vi) {
        for (int i = 0; i < from[y].size(); ++i) {
          ans[x].insert(from[y][i]);
        }
      }
    }
    for (pair<int, set<int> > pis : ans) {
      for (auto x : pis.second) {
        cout << pis.first << " " << x << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
