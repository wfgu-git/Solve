/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

int n;
ll a[maxn], b[maxn];
string ans[] = {"NO\n", "YES\n"};
void work() {
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(b, b + n);
  ll t = b[n - 1] + b[n - 2];
  t = (t >= sum);
  cout << ans[t];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
