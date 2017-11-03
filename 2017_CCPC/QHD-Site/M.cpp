/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

int get_dist(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
struct point {
  int d, id;

  bool operator < (const point & rhs) const {
    if (d == rhs.d) {
      return id < rhs.id;
    }
    return d < rhs.d;
  }
} ;
vector<point> V;
set<int> ans;
void work() {
  int T, n, R, r;
  cin >> T;
  while (T--) {
    V.clear();
    ans.clear();
    cin >> n >> R >> r;
    for (int i = 1; i <= n; ++i) {
      int x, y;
      cin >> x >> y;
      V.push_back((point){x * x + y * y, i});
    }
    sort(V.begin(), V.end());

    int d;
    if (2 * r >= R) {
      d = 2 * r - R;
      d *= d;
      for (point & p : V) {
        if (p.d <= d) {
          ans.insert(p.id);
        }
      }
    } else {
      d = R - 2 * r;
      d *= d;
      for (point & p : V) {
        if (p.d <= d) {
          ans.insert(p.id);
        }
      }
    }
    if (ans.empty()) {
      d = V[0].d;
      for (point & p : V) {
        if (p.d <= d) {
          ans.insert(p.id);
        }
      }
    }
    cout << ans.size() << '\n';
    int fi = 1;
    for (int x : ans) {
      if (fi) {
        fi = 0; cout << x;
        continue;
      }
      cout << " " << x;
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
