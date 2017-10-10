/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    if (n == 2 || n == 3) {
      cout << "second";
    } else {
      cout << "first";
    }
    cout << "\n";
  }
}
