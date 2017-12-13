/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 100000 + 20;

int c[maxn], a[maxn];
void work() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int fi = 0, se = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > se) {
      if (a[i] > fi) {
        c[a[i]]--;
      } else {
        c[fi]++;
      }
    }
    if (a[i] > fi) {
      se = fi;
      fi = a[i];
    } else if (a[i] > se) {
      se = a[i];
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (c[i] > c[ans]) {
      ans = i;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
