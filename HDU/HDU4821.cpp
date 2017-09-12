/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;


const int base = 131;
unsigned long long hstable[maxn];
unsigned long long p[maxn];
int M, L;
string s;
int n;
void init() {
  p[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    p[i] = p[i - 1] * base;
  }

  n = s.size();
  hstable[0] = 0;
  for (int i = 0; i < n; ++i) {
    hstable[i + 1] = hstable[i] * base + (s[i] - 'a' + 1);
  }
}
unsigned long long get(int l, int r) {
  return hstable[r] - hstable[l - 1] * p[r - l + 1];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  map<unsigned long long, int> mep;
  while (cin >> M >> L) {
    cin >> s;

    init();
    int ans = 0;
    for (int i = 0; i < L && i + M * L < n; ++i) {
      mep.clear();
      for (int j = i; j < i + M * L; j += L) {
        ++mep[get(j + 1, j + L)];
      }

      if (mep.size() == M) ++ans;

      unsigned long long tmp;
      for (int j = i + M * L; j + L - 1 < n; j += L) {
        tmp = get(j - M * L + 1, j - (M - 1) * L);
        mep[tmp]--;
        if (mep[tmp] == 0) mep.erase(tmp);
        ++mep[get(j + 1, j + L)];
        if (mep.size() == M) ++ans;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
