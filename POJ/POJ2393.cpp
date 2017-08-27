/*
   教练我要打ACM!
   Life has never been fucking so easy...
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int N, S;
void work() {
  int cost = inf;
  ll sum = 0;
  for (int i = 0; i < N; ++i) {
    int c, y;
    cin >> c >> y;
    cost = min(cost + S, c);
    sum += cost * 1LL * y;
  }
  cout << sum << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> N >> S) {
    work();
  }
  return 0;
}
