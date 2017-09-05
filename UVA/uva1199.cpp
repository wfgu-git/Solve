/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int N;
vector<int> floors;
vector<int> stp, ret;
bool check(int up) {
  int L = N - 1;
  for (int i = 0; i < N; ++i) {
    if ((floors[i] - 1) * 20 > up) {
      L = i;
      break;
    }
  }
  stp.clear();
  int t = 0, f = 1;
  while (true) {
    if (t + (floors[L] - f) * 4 > up) break;
    int x = (up - t + 4 * f + 20 * floors[L]) / 24;
    stp.push_back(x);
    while (L < N) {
      int fl = floors[++L];
      if (4 * (x - f) + 20 * (fl - x) > up - t) break;
    }
    if (L == N) {
      ret = stp;
      return true;
    }
    t += 10 + (x - f) * 4;
    f = x;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (cin >> N && N) {
    floors.clear(); ret.clear();
    for (int x, i = 0; i < N; ++i) {
      cin >> x;
      floors.push_back(x);
    }
    int lb = 0, ub = floors[N - 1] * 20;
    int ans;
    while (lb <= ub) {
      int mid = (lb + ub) / 2;
      if (check(mid)) {
        ans = mid;
        ub = mid - 1;
      } else {
        lb = mid + 1;
      }
    }
    cout << ans << endl;
    cout << ret.size();
    for (int i = 0; i < ret.size(); ++i) {
      cout << " " << ret[i];
    }
    cout << endl;
  }
  return 0;
}
