/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

vector<int> Set;
int a[maxn];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    Set.push_back(x);
    a[x % m]++;
  }
  sort(Set.begin(), Set.end());
  if (n == 1) {
    cout << "Yes" << '\n';
    for (int i = 0; i < k; ++i) {
      cout << Set[i] << " ";
    }
    return 0;
  }

  for (int i = 0; i < m; ++i) {
    if (a[i] >= k) {
      cout << "Yes" << '\n';
      int rems = i;
      int cont = 0;
      for (int x : Set) {
        if (x % m == rems) {
          cout << x << " ";
          cont++;
          if (cont == k) {
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << '\n';
}
