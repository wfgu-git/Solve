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

vector<string> line;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  map<char, string> f;
  string raw;
  while (cin >> raw) {
    if (raw == "END") {
      break;
    }
    line.push_back(raw.substr(0, raw.size() - 1));
  }
  int n = line.size();
  double x = 0, y = n;
  for (int i = 0; i < n; ++i) {
    char id = line[i][line[i].size() - 1];
    if (f[id] == line[i]) {
      ++x;
      cout << "Hit" << endl;
    } else {
      cout << "Miss" << endl;
      f[id] = line[i];
    }
  }
  cout << "Hit ratio = " << fixed << setprecision(2)  << 100.0 * x / y << '%' << endl;
}
