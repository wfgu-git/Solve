/*
教练我要打ACM!
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int T;
void work() {
  string raw;
  getline(cin, raw);
  raw.erase(remove(raw.begin(), raw.end(), ' '), raw.end());
  int n = raw.size();
  int cut = n / 2;
  int permute = 1 << n;
  int ans = inf;
  do {
    bitset<10> used = static_cast<bitset<10> > (permute);
    string x, y;
    for (int i = 0; i < n; ++i) {
      if (used[i]) x += (raw[i]);
      else y += (raw[i]);
    }
    if (x.size() != cut) continue;
    if (x[0] == '0' && x.size() > 1) continue;

    do {
      int tmpx = atoi(x.c_str());
      do {
        if (y[0] == '0' && y.size() > 1) continue;
        int tmpy = atoi(y.c_str());
        int diff = abs(tmpx - tmpy);
        if (diff < ans) ans = diff;
      } while (next_permutation(y.begin(), y.end()));
    } while (next_permutation(x.begin(), x.end()));
  } while(--permute);
  cout << ans << endl;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // do not use scanf/printf!!!
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  cin.ignore();
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
