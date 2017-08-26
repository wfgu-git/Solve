/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

int cont[26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();
  ll sum = 1LL * n * (n + 1) / 2 - n + 1;
  for (char x : s) {
    sum -= cont[x - 'a'];
    cont[x - 'a']++;
  }
  cout << sum << endl;
  return 0;
}
