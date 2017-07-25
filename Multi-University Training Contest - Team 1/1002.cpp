#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int moder = 1e9 + 7;
const int maxn = 100000 + 20;
ll mod_pow(int n) {
  ll base = 26, ans = 1;
  while (n) {
    if (n & 1)
      ans = ans * base % moder;
    base = base * base % moder;
    n >>= 1;
  }
  return ans;
}
int c[26][maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n) {
    string s;
    set<char> head;
    map<char, int> f;
    for (char ch = 'a'; ch <= 'z'; ++ch) head.insert(ch);
    for (int k = 0; k < n; k++) {
      cin >> s;
      int slen = s.size();
      head.erase(s[0]);
      for (int i = slen - 1; i >= 0; i--) {

      }
    }
  }
  return 0;
}
