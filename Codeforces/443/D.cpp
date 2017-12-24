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
int cont[maxn];
int S[maxn];
void work() {
  ll n, k, m;
  cin >> n >> k >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int top = 0;
  for (int i = 0; i < n; ++i) {
    S[++top] = a[i];
    if (top > 1 && S[top] == S[top - 1]) {
      cont[top] = cont[top - 1] + 1;
    } else {
      cont[top] = 1;
    }
    if (cont[top] >= k) {
      top -= k;
    }
  }

  int L = 1, R = top;
  ll side = 0, mid = (R - L + 1);
  while (S[L] == S[R] && L < R) {
    int now = 0;
    int l = L, r = R;
    while (l < r && S[l] == S[L] && now < k) {
      ++l;
      ++now;
    }
    while (l < r && S[r] == S[R] && now < k) {
      --r;
      ++now;
    }
    if (now != k) {
      break;
    }
    side += k;
    L = l;
    R = r;
  }
  mid = (R - L + 1);

  int flag = 1;
  for (int i = L + 1; i <= R; ++i) {
    if (S[i - 1] != S[i]) {
      flag = 0;
      break;
    }
  }
  if (flag) { // all the same
    if (1LL * mid * m % k == 0) {
      cout << 0 << endl;
    } else {
      cout << (1LL * mid * m % k + 1LL * side) << endl;
    }
  } else { // not all the same
    cout << 1LL * mid * m + 1LL* side << endl;
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
