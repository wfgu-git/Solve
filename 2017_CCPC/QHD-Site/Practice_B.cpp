/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const ld eps = 1e-10;

int cont[2][10];
map<string, int> mep[2];
string raw;
vector<int> fac = {2, 3, 5, 7};
void work() {
  int T;
  cin >> T;
  while (T--) {
    memset(cont, 0, sizeof(cont));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        cin >> raw;
        for (int k = 0; k < 2; ++k) {
          if (mep[k][raw] == 4) {
            cont[k][2] += 2;
            continue;
          }
          if (mep[k][raw] == 6) {
            cont[k][2]++;
            cont[k][3]++;
            continue;
          }
          cont[k][mep[k][raw]]++;
        }
      }
    }
    ld ex1 = 0, ex2 = 0;
    for (int x : fac) {
      ex1 += (ld)(cont[0][x]) * ((ld)log(x) / (ld)log(2.0));
      ex2 += (ld)(cont[1][x]) * ((ld)log(x) / (ld)log(2.0));
    }
    if (abs(ex1 - ex2) < eps) {
      cout << 'E' << '\n';
      continue;
    }
    if (ex1 > ex2) {
      cout << 'A' << '\n';
      continue;
    }
    if (ex1 < ex2) {
      cout << 'B' << '\n';
      continue;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  mep[0]["UFS2.0"] = 2;
  mep[0]["UFS2.1"] = 3;
  mep[0]["eMMC5.1"] = 5;
  mep[0]["LPDDR3"] = 4;
  mep[0]["LPDDR4"] = 6;
  mep[0]["Sparse"] = 7;
  mep[0]["Normal"] = 3;

  mep[1]["UFS2.0"] = 3;
  mep[1]["UFS2.1"] = 5;
  mep[1]["eMMC5.1"] = 2;
  mep[1]["LPDDR3"] = 7;
  mep[1]["LPDDR4"] = 3;
  mep[1]["Sparse"] = 4;
  mep[1]["Normal"] = 6;

  work();
}
