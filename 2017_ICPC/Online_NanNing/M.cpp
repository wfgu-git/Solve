/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  double a;
  vector<int> vi;
  cin >> n >> a;
  cin.get();
  string raw;
  stringstream ss;
  while (getline(cin, raw)) {
    ss.clear();
    ss << raw;
    int state = 0, x;
    while (ss >> x) {
      state |= (1 << x);
    }
    vi.push_back(state);
  }
  int t = ceil(vi.size() * 1.0 * a);
  int ret = 0;
  for (int i = 1; i <= (1 << n); ++i) {
    int cont = 0;
    for (int x : vi) {
      if ((x & i) == i) {
        cont++;
      }
    }
    if (cont >= t) {
      ret++;
    }
  }
  cout << ret << endl;
}
