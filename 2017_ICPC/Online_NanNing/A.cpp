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
const int maxn = 4;

double grid[maxn][maxn];
int a[100];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> grid[i][j];
    }
  }

  string raw;
  stringstream line;
  cin.get();
  getline(cin, raw);
  line << raw;
  int x, t = 0;
  while (line >> x) {
    a[t++] = x - 1;
  }
  double ret = 1.0;
  for (int i = 1; i < t; ++i) {
    ret *= grid[a[i - 1]][a[i]];
  }
  cout << fixed << setprecision(8) << ret << endl;

  getline(cin, raw);
  line.clear();
  line << raw;
  t = 0;
  while (line >> x) {
    a[t++] = x - 1;
  }
  ret = 1.0;
  for (int i = 1; i < t; ++i) {
    ret *= grid[a[i - 1]][a[i]];
  }
  cout << fixed << setprecision(8) << ret << endl;



  for (int k = 0; k < 2; ++k) {
    cin >> x; --x;
    ret = 0;
    for (int i = 1; i < 200; ++i) {
      ret += i * (1 - grid[x][x]) * pow(grid[x][x], i - 1);
    }
    cout << fixed << setprecision(8) << ret << endl;
  }
}
