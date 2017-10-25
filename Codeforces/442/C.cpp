/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int a[maxn];
vector<int> V;
void work() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0) V.push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (i % 2 != 0) V.push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0) V.push_back(i);
  }
  cout << V.size() << '\n';
  for (int x : V) {
    cout << x << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
