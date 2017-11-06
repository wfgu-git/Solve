/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

void work() {
  string raw;
  cin >> raw;
  int n = raw.size();
  int i;
  for (i = 0; i < n; ++i) {
    if (raw[i] == '1') break;
  }
  int cont = 0;
  for (int j = i + 1; j < n; ++j) {
    if (raw[j] == '0') {
      cont++;
    }
  }
  if (cont >= 6) {
    cout << "yes";
    return;
  }
  cout << "no";
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
