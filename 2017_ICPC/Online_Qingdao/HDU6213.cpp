
/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

map<string, int> tid;
void init() {
  string raw = "rat, ox, tiger, rabbit, dragon, snake, horse, sheep, monkey, rooster, dog, pig";
  auto sz = remove(raw.begin(), raw.end(), ',');
  raw.erase(sz, raw.end());
  stringstream ss(raw);
  string tmp;
  int cont = 1;
  while (ss >> tmp) {
    tid[tmp] = cont++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  init();
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    string x, y;
    cin >> x >> y;
    if (tid[x] == tid[y]) {
      cout << 12 << endl;
    } else {
      cout << (tid[y] - tid[x] + 12) % 12 << endl;
    }
  }
  return 0;
}
