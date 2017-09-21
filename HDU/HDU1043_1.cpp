/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

// tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> trees[maxn];
// tree<pii, null_type, greater<pii>, splay_tree_tag, tree_order_statistics_node_update> trees[maxn];
// tree<pii, null_type, greater<pii>, ov_tree_tag, tree_order_statistics_node_update> trees[maxn];

set<string> f;
map<string, string> mep;
int sz = 0;
string dir = "durl";
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct node {
  string s;
  string path;
  int pos;

} ;
bool check(int x, int y) {
  if (x < 0 || x > 2 || y < 0 || y > 2) return 0;
  return 1;
}
void init() {
  string s = "12345678x";
  queue<node> Q;
  Q.push((node){s, "", 8});
  mep[s] = "";
  f.insert(s);

  int x, y, tx, ty;
  int tp;
  while (!Q.empty()) {
    node now = Q.front(); Q.pop();
    x = now.pos / 3;
    y = now.pos % 3;
    for (int i = 0; i < 4; ++i) {
      tx = x + dx[i];
      ty = y + dy[i];
      if (!check(tx, ty)) continue;
      tp = 3 * tx + ty;
      swap(now.s[now.pos], now.s[tp]);
      if (f.find(now.s) != f.end()) {
        swap(now.s[now.pos], now.s[tp]);
        continue;
      }
      Q.push((node){now.s, dir[i] + now.path, tp});
      f.insert(now.s);
      mep[now.s] = dir[i] + now.path;
      swap(now.s[now.pos], now.s[tp]);
    }
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  init();
  string raw;
  while (getline(cin, raw)) {
    raw.erase(remove(raw.begin(), raw.end(), ' '), raw.end());
    // cout << raw << endl;
    if (mep[raw] == "") {
      cout << "unsolvable";
    } else {
      cout << mep[raw];
    }
    cout << endl;
  }
}
