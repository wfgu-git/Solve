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
const int maxn = 22 + 20;

int n;
struct node {
  int val, pos;
  bool operator < (const node & rhs) const {
    return val < rhs.val;
  }
} a[maxn];
int b[maxn];
void work() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i] = {x, i};
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    b[a[i].pos] = a[(i + 1) % n].val;
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
