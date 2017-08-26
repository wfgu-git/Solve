/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const ld eps = 1e-11;

int sx, sy, ex, ey;
int xmax, xmin, ymax, ymin;
int N;
vector<pii> st, tmp;
bool check(pii q) {
  if (q.first < xmin || q.first > xmax || q.second < ymin || q.second > ymax) return false;
  return true;
}
void work() {
  xmax = max(sx, ex);
  xmin = min(sx, ex);
  ymax = max(sy, ey);
  ymin = min(sy, ey);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    tmp.push_back({x, y});
  }
  for (pii& x : tmp) {
    if (check(x)) st.push_back(x);
  }
  for ()
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> sx >> sy >> ex >> ey) {
    work();
  }
  return 0;
}
