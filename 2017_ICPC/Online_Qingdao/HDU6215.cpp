/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int T;
int a[maxn];
int nxt[maxn], pre[maxn], del[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    cin >> n;
    vector<int> vi;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      pre[i] = i - 1;
      nxt[i] = i + 1;
      vi.push_back(i);
    }
    a[0] = -inf;
    a[n + 1] = inf;
    pre[1] = 0;
    nxt[0] = 1;
    pre[n + 1] = n;
    nxt[n] = n + 1;
    memset(del, 0, sizeof(del));
    vector<int> tmp;
    while (vi.size()) {
      tmp.clear();
      for (int& x : vi) {
        int go = nxt[x];
        int bk = pre[x];
        if (a[bk] > a[x]) {
          tmp.push_back(bk);
          tmp.push_back(x);
        }
        if (a[go] < a[x]) {
          tmp.push_back(x);
          tmp.push_back(go);
        }
      }
      vi.clear();
      for (int& x : tmp) {
        if (!del[x]) {
          del[x] = 1;
          int go = nxt[x];
          int bk = pre[x];
          nxt[bk] = go;
          pre[go] = bk;
          vi.push_back(bk);
        }
      }
    }
    vector<int> ans;
    for (int i = nxt[0]; i != n + 1; i = nxt[i]) {
      ans.push_back(a[i]);
    }
    cout << ans.size() << endl;
    for (int& x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
