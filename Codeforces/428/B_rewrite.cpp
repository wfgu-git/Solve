/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, k;
int cont[maxn];
int seat[5];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    ++cont[x];
  }
  seat[2] = n * 2;
  seat[4] = n;
  for (int i = maxn - 1; i > 0; --i) while (cont[i]--) {
    int j, t;
    for (j = 4; j > 0; j--) {
      t = min(i, j);
      if (seat[j]) {
        --seat[j];
        ++cont[i - t];
        if (j - t > 1) {
          ++seat[j - t - 1];
        }
        break;
      }
    }

    if (!j) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}
