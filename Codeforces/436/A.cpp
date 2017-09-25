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

int a[101];
int main() {
  int n;
  cin >> n;
  map<int, int> f;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    f[x]++;
  }
  if (f.size() == 2) {
    pair<int, int> a, b;
    auto iter = f.begin();
    a = *iter;
    b = *++iter;
    if (a.second == b.second) {
      cout << "YES" << endl;
      cout << a.first << " " << b.first << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
