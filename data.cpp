/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  srand(time(0));
  freopen("/home/wfgu/solve/data.in", "w", stdout);
  for (int i = 0; i < 100; ++i) {
    string a, b;
    int x;
    for (int j = 0; j < 50; ++j) {
      x = rand() % 10;
      a.push_back((char)('0' + x));
    }
    for (int j = 0; j < 50; ++j) {
      x = rand() % 10;
      b.push_back((char)('0' + x));
    }
    cout << a << '\n' << b << '\n';
    cout << endl;
  }
  return 0;
}
