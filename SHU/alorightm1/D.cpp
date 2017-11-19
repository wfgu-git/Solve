/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 50 + 20;

int w[maxn];
struct node {
  int w;
  int fa, lson, rson;
} ;
node nds[maxn * 2 + 1];
string ans[maxn];
struct comp {
  bool operator () (const pair<int, int>& x, const pair<int, int>& y) const {
    if (x.first == y.first) {
      return x.second < y.second;
    }
    return x.first > y.first;
  }
} ;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    cin >> n;
    priority_queue<pii, vector<pii>, comp> Q;
    for (int i = 0; i < n; ++i) {
      ans[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
      nds[i] = {w[i], -1, -1, -1};
      Q.push({w[i], i});
    }

    for (int i = n; i < 2 * n - 1; ++i) {
      nds[i] = {0, -1, -1, -1};
    }
    pii tr, tl;
    int trv, tlv;
    int trid, tlid;
    for (int i = n; i < 2 * n - 1; ++i) {
      tr = Q.top(); Q.pop();
      trv = tr.first;
      trid = tr.second;
      tl = Q.top(); Q.pop();
      tlv = tl.first;
      tlid = tl.second;
      nds[tlid].fa = i;
      nds[trid].fa = i;
      nds[i].lson = tlid;
      nds[i].rson = trid;
      nds[i].w = tlv + trv;
      Q.push({nds[i].w, i});
    }

    for (int i = 0; i < n; ++i) {
      int now = i;
      int fa = nds[i].fa;
      while (fa != -1) {
        if (nds[fa].lson == now) {
          ans[i].push_back('0');
        } else {
          ans[i].push_back('1');
        }
        now = fa;
        fa = nds[now].fa;
      }
      reverse(ans[i].begin(), ans[i].end());
    }

    cout << "Case " << cas << '\n';
    for (int i = 0; i < n; ++i) {
      cout << w[i] << " " << ans[i] << '\n';
    }
    cout << endl;
  }
}
