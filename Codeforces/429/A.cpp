/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

void work() {
  int n, k;
  string str;
  cin >> n >> k;
  cin >> str;

  map<char, int> mep;
  for (char & ch : str) {
    if (mep.count(ch)) mep[ch]++;
    else mep.insert({ch, 1});
  }

  for (auto kv : mep) {
    if (kv.second > k) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
