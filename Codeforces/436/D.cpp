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
const int maxn = 200000 + 20;

int a[maxn];
set<int> U;
int appear[maxn];
bool mark[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    U.insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    appear[a[i]]++;
    U.erase(a[i]);
  }
  cout << U.size() << endl;
  for (int i = 1; i <= n; ++i) {
    if (appear[a[i]] > 1) {
      if (*U.begin() < a[i]) {
        appear[a[i]]--;
        a[i] = *U.begin();
        U.erase(U.begin());
      } else {
        if (!mark[a[i]]) {
          mark[a[i]] = 1;
        } else {
          appear[a[i]]--;
          a[i] = *U.begin();
          U.erase(U.begin());
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}
