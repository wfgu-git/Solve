/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  double Q, H, S, D, N;
  while (cin >> Q >> H >> S >> D >> N) {
    set<pair<double, double> > st;
    st.insert({Q * 4.0, 0.25});
    st.insert({H * 2.0, 0.5});
    st.insert({S, 1});
    st.insert({D / 2.0, 2});
    ll sum = 0;
    while (N > 0) {
      pair<double, double> now = *st.begin();
      st.erase(st.begin());
      if (N < now.second) continue;
      int k = floor(1.0 * N / now.second);
      sum += 1LL * k * now.first * now.second;
      N -= 1.0 * k * now.second;
    }
    cout << sum << endl;
  }
  return 0;
}
