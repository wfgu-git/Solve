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

ll lcm(ll x, ll y) {
  return x / __gcd(x, y) * y;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  while (cin >> n >> m) {
    cout << lcm(n - 1, m - 1) + (n + m - 2) / __gcd(n - 1, m - 1) - ((n - 1) * (m - 1)) / (__gcd(n - 1, m - 1) * __gcd(n - 1, m - 1));
    cout << endl;
  }
  return 0;
}
