/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, sum;
void work() {
  vector<int> st;
  for (int i = 1; i <= n; ++i) st.push_back(i);
  do {
    vector<int> tmp = st;
    for (int i = n; i > 1; --i) {
      for (int j = 0; j < i - 1; ++j) {
        tmp[j] = tmp[j] + tmp[j + 1];
      }
    }
    if (tmp[0] == sum) {
      for (int i = 0; i < n; ++i) {
        if (i != n - 1) cout << st[i] << " ";
        else cout << st[i] << endl;
      }
      return;
    }
  } while (next_permutation(st.begin(), st.end()));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> sum) {
    work();
  }
  return 0;
}
